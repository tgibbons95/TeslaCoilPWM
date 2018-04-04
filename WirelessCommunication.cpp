#include "Headers/WirelessCommunication.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <linux/if_link.h>
#include <fcntl.h>
#include <string>
#include <iostream>

#define DEFAULT_PORT 3456
#define DEFAULT_BROADCAST "192.168.0.255"

// Contructor (no parameters)
WirelessCommunication::WirelessCommunication(){
	this->iPortNumber = DEFAULT_PORT;
	this->iLengthOfServer = sizeof(this->server);
	this->iLengthOfFrom = sizeof(this->from);
	this->SetupConnections();
}

// Constructor (port number)
WirelessCommunication::WirelessCommunication(int data){
	this->iPortNumber = data;
	this->iLengthOfServer = sizeof(this->server);
	this->iLengthOfFrom = sizeof(this->from);
	this->SetupConnections();
}

// Setup Wireless Connection for Receiving and Broadcasting
void WirelessCommunication::SetupConnections(){
	// Setup Socket
	this->iSocketFD = socket(AF_INET, SOCK_DGRAM, 0);
	if ((this->iSocketFD) < 0)
		this->Error("socket");

   	// Setup Server information
	bzero(&(this->server),(this->iLengthOfServer));

	server.sin_family = AF_INET; // symbol constant for Internet domain
	server.sin_addr.s_addr = INADDR_ANY; // IP address of the machine on which
	server.sin_port = htons(this->iPortNumber); // port number

	// Bind Socket
   	if (bind((this->iSocketFD), (struct sockaddr *)&(this->server), (this->iLengthOfServer)) < 0)
       		this->Error("bind");

	// Set Socket Options for Broadcast
	int boolval = 1;
	if (setsockopt((this->iSocketFD), SOL_SOCKET, SO_BROADCAST, &boolval, sizeof(boolval)) < 0)
	{
		this->Error("set socket options\n");
	}
	
	anybody.sin_family = AF_INET;		// symbol constant for Internet domain
	anybody.sin_port = htons(this->iPortNumber);				// port field
	anybody.sin_addr.s_addr = inet_addr(DEFAULT_BROADCAST);	// broadcast address

}

void WirelessCommunication::Error(const char* data){
	std::cout << data << std::endl;
	this->ErrorMessage = data;
}

std::string WirelessCommunication::Receive(){
	// String buffer	
	char buffer[LOG_SIZE];
	bzero(buffer,LOG_SIZE);

	recvfrom((this->iSocketFD), buffer, LOG_SIZE, 0, (struct sockaddr *)&(this->from), &(this->iLengthOfFrom));

	this->LastMessage = buffer;
	
	return this->LastMessage;
}

int WirelessCommunication::Send(){
	int n;
	char buffer[LOG_SIZE];	// to store received messages or messages to be sent.

	int length = sizeof(struct sockaddr_in);		// size of structure
    

	// bzero: to "clean up" the buffer. The messages aren't always the same length...
	bzero(buffer,LOG_SIZE);		// sets all values to zero. memset() could be used

	fflush(stdout);
	fgets(buffer, LOG_SIZE-1, stdin); // LOG_SIZE-1 because a null character is added

	if (buffer[0] != '!') {
		
		// send message to anyone there...
		n = sendto(iSocketFD, buffer, strlen(buffer), 0, (const struct sockaddr *)&anybody, length);

		if (n < 0) 
			this->Error("Sendto");
	  
	}

	
	return 1;
}

WirelessCommunication::~WirelessCommunication(){

}
