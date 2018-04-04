#include "Headers/SoundPlayer.h"
#include <wiringPi.h>
#include <iostream>
#include <unistd.h>

#define DEFAULT_SPEAKER_PORT 29

#define HIGH 	1
#define LOW 	0

#define OUTPUT 	1
#define INPUT 	0

#define CHAR_DEV "/dev/TeslaCoil"
#define MSG_SIZE 50			// message size


#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <linux/if_link.h>
#include <fcntl.h>

// Contructor (no parameters)
SoundPlayer::SoundPlayer(){
	this->iSpeakerGpioPin = 29;
	this->bUseKernel = false;
	this->SetupConnections();
}

// Constructor (Pin number)
SoundPlayer::SoundPlayer(int iSpeakerGpioPin, bool bUseKernel){
	this->iSpeakerGpioPin = iSpeakerGpioPin;
	this->bUseKernel = bUseKernel;
	this->SetupConnections();
}

// Similarities within each constructor
void SoundPlayer::SetupConnections(){
	// Initialize the board
	if(wiringPiSetup() < 0) {
		// Exit on board fail
		this->Error("Initialization of the GPIO has failed...\n");
	}	

	// Open the Character Device for writing
	if((cdev_id = open(CHAR_DEV, O_WRONLY)) == -1) {
		this->Error("Cannot open device...\n");
		//exit(1);
	}

	// Change speaker to output
	pinMode(this->iSpeakerGpioPin, OUTPUT);

	// Set speaker low
	digitalWrite(this->iSpeakerGpioPin, LOW);
}

// Play note set amount of times
void SoundPlayer::PlayNote(unsigned int Note, int iAmountOfTimesToPlay){

	if(!this->bUseKernel){
		for(int i = 0; i < iAmountOfTimesToPlay; i++){
			// Set speaker high
			digitalWrite(this->iSpeakerGpioPin, HIGH);
			usleep(Note);

			// Set speaker low
			digitalWrite(this->iSpeakerGpioPin, LOW);
			usleep(Note);
		}
	}
	else{

		char buffer[MSG_SIZE];
		snprintf(buffer, sizeof(buffer), "@a %d",Note);
		write(cdev_id, buffer, sizeof(buffer));
		char buffer2[MSG_SIZE];
		snprintf(buffer2, sizeof(buffer2), "@b %d",iAmountOfTimesToPlay);
		//printf("\nNote: %d\tCount: %d",Note, iAmountOfTimesToPlay);
		write(cdev_id, buffer2, sizeof(buffer2));
		usleep(Note * iAmountOfTimesToPlay);
	}
	usleep(250000);
}

// Play note indefinitely
void SoundPlayer::PlayNoteIndefinitely(int Note){
	while(1){
		// Set speaker high
		digitalWrite(this->iSpeakerGpioPin, HIGH);
		usleep(Note);

		// Set speaker low
		digitalWrite(this->iSpeakerGpioPin, LOW);
		usleep(Note);
	}
}

void SoundPlayer::SlightPause(){
	usleep(500000);
}

void SoundPlayer::Error(const char* data){
	std::cout << data << std::endl;
	this->ErrorMessage = data;
}

SoundPlayer::~SoundPlayer(){
	close(cdev_id);
}
