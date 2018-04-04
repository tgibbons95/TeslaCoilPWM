#include "Headers/PythonCommunication.h"

PythonCommunication::PythonCommunication(){
	
	pthread_create(&this->CommunicationThread, NULL, Communicate, NULL);
}

int PythonCommunication::getSelection(){
	return iPipeValue;
}

void* Communicate(void* data){
	
}
