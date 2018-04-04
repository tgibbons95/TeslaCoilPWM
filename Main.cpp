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
	while(1){
		//printf("Enter task: ");
		scanf("%d",&iLocalVariable);
		sem_wait(&TaskLock);
		g_thisTask = iLocalVariable;
		sem_post(&TaskLock);
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

