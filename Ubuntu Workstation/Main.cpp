#include <string>
#include "Headers/WirelessCommunication.h"
#include <iostream>


// Macros
#define SAFE_DELETE(x) if(x != NULL) delete x

// Global Socket Communication Class
WirelessCommunication* g_pCommunication;


int main(void){

	g_pCommunication = new WirelessCommunication(2050);
	
	while(1){
		std::cout << "\n String to send: ";
		g_pCommunication->Send();

	}

	SAFE_DELETE(g_pCommunication);

	return 1;
}
