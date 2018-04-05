#include "Headers/Notes.h"
#include "Headers/Songs.h"
#include "Headers/WirelessCommunication.h"
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <wiringPi.h>
//#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;

// Macros
#define SAFE_DELETE(x) if(x != NULL) delete x

// Global Socket Communication Class
WirelessCommunication* g_pCommunication;

// Global Speaker Object
SoundPlayer* g_pSpeaker;

// Global Song Object
Song* g_pSong1;
Song* g_pSong2;
Song* g_pNote;

void* Play(void* data);
void* Communicate(void* data);
int WhatToDo();
void getSqlCommand();
void postSqlCommand();
void runCommand(string);

string webFreq;
//string webFreqOld;
string piFreq;
int webActivity;
//int webActivityOld;
int piActivity;
string sqlStart = "mysql -h capstonedatabase.cbjo3wuam9ez.us-west-2.rds.amazonaws.com -u dbsuperadmin -p1Rc8TAv39W epiz_21734938_controller -e";
string piIP = "10.50.1.23";

int g_thisTask = 2;
sem_t TaskLock;
sem_t ThreadLock;

#define SPEAKER_GPIO_PIN_NO 29

#define HIGH 	1
#define LOW 	0

#define OUTPUT 	1
#define INPUT 	0



int main(int argc, char* argv[]) {

	// Load Songs for faster speed
	g_pSong1 = new Song(0);
	g_pSong2 = new Song(1);
	g_pNote = new Song("C5");

	bool bUseKernel = true;
	if(argc > 1){
		bUseKernel = (bool)atoi(argv[1]);
		printf("\nUse kernel: %s\n", (bUseKernel ? "TRUE" : "FALSE"));
	}

	// Initialize global variables
	//g_pCommunication = new WirelessCommunication(2050);
	g_pSpeaker = new SoundPlayer(SPEAKER_GPIO_PIN_NO, bUseKernel);

	// Initialize Task Lock
	sem_init(&TaskLock, 0, 1);
	sem_init(&ThreadLock, 0, 0);

	// Initialize threads
	pthread_t PlayThread;
	pthread_t CommunicationThread;
	pthread_create(&CommunicationThread, NULL, Communicate, NULL);
	//pthread_create(&ReceivingThread, NULL, Receive, NULL);

	int x;
	while(1){
		sem_wait(&TaskLock);
		x = g_thisTask;
		sem_post(&TaskLock);
		switch(x){
			case -1: /*DO NOTHING AND CONTINUE PLAYING*/ break;
			case 1: 
			case 2:
			case 3:
				g_pSong1->Pause();
				g_pSong2->Pause();
				g_pNote->Pause();
				pthread_join(PlayThread, NULL);
				g_pSpeaker->SlightPause();
				pthread_create(&PlayThread, NULL, Play, (void*)(&x));
				sem_wait(&ThreadLock);
				sem_wait(&TaskLock);
				g_thisTask = -1;
				sem_post(&TaskLock);
				break;
			default:	
				g_pSong1->Pause();
				g_pSong2->Pause();
				g_pNote->Pause();
				sem_wait(&TaskLock);
				g_thisTask = -1;
				sem_post(&TaskLock);
				break;
		}
	}
	//PlayHarryPotter(g_pSpeaker);
	// Join threads
	//pthread_join(ReceivingThread, NULL);
	
	// Free allocated space
	//SAFE_DELETE(g_pCommunication);
	SAFE_DELETE(g_pSpeaker);
	SAFE_DELETE(g_pSong1);
	SAFE_DELETE(g_pSong2);
	SAFE_DELETE(g_pNote);

	return 0;
}

void* Communicate(void* data){
	int iLocalVariable = 0;
	int iTemp = 0;
	static int iPreviousTask = -1;
	while(1){
		//printf("Enter task: ");
		usleep(5000000);		
		getSqlCommand();
		iTemp = webActivity;
		if(iTemp == iPreviousTask)
			iLocalVariable = -1;
		else
			iLocalVariable = iTemp;

		iPreviousTask = iTemp;

		scanf("%d",&iLocalVariable);
		sem_wait(&TaskLock);
		g_thisTask = iLocalVariable;
		sem_post(&TaskLock);
		postSqlCommand();
	}
}

void* Play(void* data){
	int iWhatToDo = *((int*)data);
	sem_post(&ThreadLock);
	//printf("\nPlay: %d\t%p",iWhatToDo, &iWhatToDo);
	switch(iWhatToDo){
		case 1:	g_pSong1->Play(g_pSpeaker); break;
		case 2: g_pSong2->Play(g_pSpeaker); break;
		case 3: g_pNote->Play(g_pSpeaker); break;
		default: g_pSong2->Play(g_pSpeaker); break;
	}
	return NULL;
}

void postSqlCommand(){

ostringstream convert;
convert << piActivity;
string tempPiActivity = convert.str();
	//string sqlUpdate =  "\"UPDATE CoilCommands SET PI_ACTIVITY = '"+piActivity+"', PI_FREQ='"+piFreq+"' where PI_IP = '"+piIP+"'\"";
string sqlUpdate = "\"UPDATE CoilCommands SET PI_ACTIVITY = '"+tempPiActivity+"', PI_FREQ='"+piFreq+"' where PI_IP = '"+piIP+"'\"";
cout<<sqlUpdate<<"\n";
runCommand(sqlUpdate);

}

void getSqlCommand(){
	int i=0;
	string str[100];
	string sqlGet = "\"SELECT WEB_FREQ, WEB_ACTIVITY FROM CoilCommands WHERE PI_IP = '"+piIP+"'\" > output.txt";
	//cout<<sqlGet<<"\n";
	runCommand(sqlGet);
	fstream filestr;
  	filestr.open ("output.txt");
	if (filestr.is_open())
  	{
		while (!filestr.eof()){    		
		filestr >> str[i];
		//cout<<str[i]<<"\n";
		i++;
		}
		filestr.close();
  	}
 	else
 	{
    		cout << "Error opening file\n";
  	}
	//cout<<i<<"\n";
	if(i==5){
		piFreq=str[2];
		piActivity=atoi(str[3].c_str());
		//cout<<"New piFreq = "<<piFreq<<" New piActivity = "<<piActivity<<"\n";
	}

return;
}


void runCommand(string sqlString){
	string command = sqlStart + sqlString;
	const char* sqlCommand = command.c_str();
	//cout<<"\n\n\n";
	//cout<<sqlCommand;
	//cout<<"\n\n\n";
	system(sqlCommand);
	return;
}

