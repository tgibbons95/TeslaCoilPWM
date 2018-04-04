#pragma once
#include "SoundPlayer.h"
#include <fstream>
#include <vector>
#include <iostream>

void PlayTwinkleTwinkleLittleStar(SoundPlayer* g_pSpeaker);
void PlayStarWars(SoundPlayer* g_pSpeaker);
void PlayHarryPotter(SoundPlayer* g_pSpeaker);

typedef struct _NoteDurationPair {
	std::string Note;
	int iDuration;
} NoteDurationPair;


class Song{

	public:
		Song(int iSongSelection);
		~Song();
		void Play(SoundPlayer* g_pSpeaker);
		void Pause();

	protected:
	
	private:
		std::vector<NoteDurationPair> SongLine;
		bool bPlayingOrPaused;
		
};
