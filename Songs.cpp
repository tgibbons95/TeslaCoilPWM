#include "Headers/Songs.h"
#include <algorithm>
#include <string>

#define NUMBER_OF_NOTES 20
#define NUMBER_OF_BEATS	90

void PlayTwinkleTwinkleLittleStar(SoundPlayer* g_pSpeaker){
	// Line 1
	g_pSpeaker->PlayNote(C4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(C4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(G4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(G4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(A4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(A4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(G4,HALF_NOTE);
	g_pSpeaker->SlightPause();

	// Line 2
	g_pSpeaker->PlayNote(F4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(F4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(E4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(E4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(D4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(D4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(C4,HALF_NOTE);
	g_pSpeaker->SlightPause();

	// Line 3
	g_pSpeaker->PlayNote(G4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(G4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(F4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(F4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(E4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(E4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(D4,HALF_NOTE);
	g_pSpeaker->SlightPause();

	// Line 4
	g_pSpeaker->PlayNote(G4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(G4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(F4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(F4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(E4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(E4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(D4,HALF_NOTE);
	g_pSpeaker->SlightPause();

	// Line 5
	g_pSpeaker->PlayNote(C4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(C4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(G4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(G4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(A4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(A4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(G4,HALF_NOTE);
	g_pSpeaker->SlightPause();

	// Line 6
	g_pSpeaker->PlayNote(F4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(F4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(E4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(E4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(D4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(D4,QUARTER_NOTE);
	g_pSpeaker->PlayNote(C4,HALF_NOTE);
	g_pSpeaker->SlightPause();
}

void PlayStarWars(SoundPlayer* g_pSpeaker){
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 11*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 11*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D5, 6*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E5, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D5, 6*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D5, 6*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E5, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D_sharp6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C_sharp6, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 11*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 11*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D_sharp6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C_sharp6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G_sharp6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 8*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F5, 4*NUMBER_OF_BEATS);
}

void PlayHarryPotter(SoundPlayer* g_pSpeaker){
	g_pSpeaker->PlayNote(B5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E6, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A6, 6*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F_sharp6, 6*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E6, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B5, 10*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E6, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D7, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C_sharp7, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C7, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C7, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F_sharp6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E6, 10*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C7, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp5, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B5, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 10*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(D7, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C_sharp7, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C7, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(C7, 3*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(B6, 1*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(A_sharp6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(F_sharp6, 4*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(G6, 2*NUMBER_OF_BEATS);
	g_pSpeaker->PlayNote(E6, 10*NUMBER_OF_BEATS);

}

Song::Song(int iSongSelection){
	// Open files
    std::fstream read;
	std::string currentString;
	std::string filename;
	switch(iSongSelection){
		case 0:		filename = "MidiFiles/_HarryPotter.mid.txt"; 		break;
		case 1:		filename = "MidiFiles/_Star_Wars_Theme.mid.txt";	break;
		default: 	filename = "MidiFiles/_Star_Wars_Theme.mid.txt";	break;
	}
    read.open(filename.data(), std::fstream::in);
	NoteDurationPair thisPair;

    while(!read.eof()){
		getline(read, thisPair.Note, ' ');
		getline(read, currentString, '\n');

 		std::replace( thisPair.Note.begin(), thisPair.Note.end(), '\n', ' ');
		std::replace( currentString.begin(), currentString.end(), '\n', ' ');

		thisPair.iDuration = std::stoi(currentString);

		if(thisPair.Note.size() > 1) {
			SongLine.push_back(thisPair);
			std::cout << thisPair.Note << "\t";
        	std::cout << thisPair.iDuration << std::endl;
		}
	}
	std::cout << std::endl;
    read.close();

}

Song::~Song(){

}

void Song::Play(SoundPlayer* g_pSpeaker){
	int iSongLength = SongLine.size();
	bPlayingOrPaused = true;
	for(int i = 0; i < iSongLength; i++) {
		if(bPlayingOrPaused){
			std::cout << "\t" <<  i;
			g_pSpeaker->PlayNote(
				ConvertCharsToNoteFrequency(SongLine[i].Note,0), 
				SongLine[i].iDuration*NUMBER_OF_BEATS);
		}
		else
			break;
	}
	
}

void Song::Pause(){
	bPlayingOrPaused = false;
}
