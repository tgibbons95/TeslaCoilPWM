#include <cstdlib>

int main(void){
	system("sudo insmod /home/pi/ECE4970/Kernel/Kernel.ko");
	system("sudo mknod /dev/TeslaCoil c 244 0");
	system("sudo chmod go+w /dev/TeslaCoil");
	system("/home/pi/ECE4970/main");
	return 0;	
}
