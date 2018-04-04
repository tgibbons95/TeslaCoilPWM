#pragma once
#include "SoundPlayer.h"
#include <fstream>
#include <vector>
#include <iostream>

typedef struct _NoteDurationPair {
	std::string Note;
	int iDuration;
} NoteDurationPair;


class Song{

	public:
		Song(int iSongSelection);
		Song(std::string Note);
		~Song();
		void Play(SoundPlayer* g_pSpeaker);
		void Pause();

	protected:
	
	private:
		std::vector<NoteDurationPair> SongLine;
		bool bPlayingOrPaused;
		bool bNoteOrSong;
		std::string thisNote;
		
};
