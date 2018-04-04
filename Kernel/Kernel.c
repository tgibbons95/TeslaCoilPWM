#ifndef MODULE
#define MODULE
#endif
#ifndef __KERNEL__
#define __KERNEL__
#endif

#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/io.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/hrtimer.h>
#include <linux/ktime.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");

// base address and length for ioremap
#define GPIOBASE 	0x3F200000
#define LENGTH 		4096

// To select input/output
#define PINS_TO_OUTPUT 	0x00040000	// pins 6

// Turn on Speaker Mask
#define SPEAKER 	0xFFFFFFFF	// pin 6

// Offsets to each register
#define SET 7
#define CLEAR 10

// pointers for registers using offsets above
static unsigned int 	*setReg,
			*clearReg;


int mydev_id;
unsigned long timer_interval_ns = 350e3;	// timer interval length (nano sec part)
long int iAmountOfNotesToPlay = 10;
long int timer_interval_us = 350e3;
static struct hrtimer hr_timer;

// Specify the notes to be played
#define NOTE1 2273
#define NOTE2 2025
#define NOTE3 1911
#define NOTE4 1703
#define NOTE5 1517
#define NOTE6 1432
#define NOTE7 1276

#define MSG_SIZE 50
#define CDEV_NAME "TeslaCoil"	// "YourDevName"

static int major;
static char msg[MSG_SIZE];

// Function called when the user space program reads the character device.
static ssize_t device_read(struct file *filp, char __user *buffer, size_t length, loff_t *offset)
{
	// Whatever is in msg will be placed into buffer, which will be copied into user space
	ssize_t dummy = copy_to_user(buffer, msg, length);	// dummy will be 0 if successful
	if(dummy != 0)
		printk("ERROR COPYING TO USER\n");

	// msg should be protected (e.g. semaphore). Not implemented here, but you can add it.
	msg[0] = '\0';	// "Clear" the message, in case the device is read again.
					// This way, the same message will not be read twice.
					// Also convenient for checking if there is nothing new, in user space.

	return length;
}

// Function called when the user space program writes to the Character Device.
static ssize_t device_write(struct file *filp, const char __user *buff, size_t len, loff_t *off)
{
	ssize_t dummy;

	if(len > MSG_SIZE)
		return -EINVAL;

	// unsigned long copy_from_user(void *to, const void __user *from, unsigned long n);
	dummy = copy_from_user(msg, buff, len);	// Transfers the data from user space to kernel space
	if(len == MSG_SIZE)
		msg[len-1] = '\0';	// will ignore the last character received.
	else
		msg[len] = '\0';

	if(msg[0] == '@'){
		switch(msg[1]){
		case 'A':
		case 'a':	kstrtol(buff + 3, 10, &timer_interval_us); 	timer_interval_ns= timer_interval_us*1000;	break;
		case 'B':
		case 'b':	kstrtol(buff + 3, 10, &iAmountOfNotesToPlay); 	break;
		case '!':	printk("Turning off sound\n");	timer_interval_ns = 1e9;	break;
		default: 	printk("Unrecognized note\n");	break;
		}
	}

	// You may want to remove the following printk in your final version.
	//printk("%s\n",buff);


	return len;		// the number of bytes that were written to the Character Device.
}

// structure needed when registering the Character Device.
static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
};

enum hrtimer_restart timer_callback(struct hrtimer *timer_for_restart)
{	
	static int dummy = 0;

	ktime_t currtime, interval;
	unsigned long overruns = 0;
	
  	currtime  = ktime_get();
  	interval = ktime_set(0, timer_interval_ns);

  	overruns = hrtimer_forward(timer_for_restart, currtime, interval);
	
	// Switch the speaker every other run of the timer
	if(iAmountOfNotesToPlay != 0){
		if(dummy == 0){
			// Set speaker high
			iowrite32(SPEAKER, setReg);
		} 
		else {
			// Set speaker low
			iowrite32(SPEAKER, clearReg);	
		}
		dummy = (dummy + 1) % 2;

		iAmountOfNotesToPlay--;
	}
	return HRTIMER_RESTART;
}

//pointer to map space
static unsigned int *gpio;
static ktime_t ktime;

int init_module()
{
	// register the Characted Device and obtain the major (assigned by the system)
	major = register_chrdev(0, CDEV_NAME, &fops);
	if (major < 0) {
     		printk("Registering the character device failed with %d\n", major);
	     	return major;
	}
	printk("Lab6_cdev_kmod example, assigned major: %d\n", major);
	printk("Create Char Device (node) with: sudo mknod /dev/%s c %d 0\n", CDEV_NAME, major);

	//map address space
	gpio = (unsigned int *)ioremap(GPIOBASE, LENGTH);

	//setup pointers		
	setReg = gpio + SET;
	clearReg = gpio + CLEAR;

	// Set up input/output pins
	iowrite32(PINS_TO_OUTPUT, gpio);

	//setup Timer	
	ktime = ktime_set(0, timer_interval_ns);
	hrtimer_init(&hr_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	hr_timer.function = &timer_callback;
	hrtimer_start(&hr_timer, ktime, HRTIMER_MODE_REL);

	
	printk("Button Detection enabled.\n");
	return 0;
}

// Cleanup - undo whatever init_module did
void cleanup_module()
{
	// cancels the timer if not restarted or cancelled before
  	int ret = hrtimer_cancel(&hr_timer);	
  	if(ret)
		printk("The timer was still in use...\n");
	else
		printk("The timer was already cancelled...\n");	
	
  	printk("HR Timer module uninstalling\n");

	// Once unregistered, the Character Device won't be able to be accessed
	unregister_chrdev(major, CDEV_NAME);
	printk("Char Device /dev/%s unregistered.\n", CDEV_NAME);

	printk("Button Detection disabled.\n");
}
