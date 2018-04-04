#include "Headers/Songs.h"
#include <algorithm>
#include <string>

#define NUMBER_OF_NOTES 20
#define NUMBER_OF_BEATS	90

Song::Song(int iSongSelection){
	// Open selected song
    std::fstream read;
	std::string currentString;
	std::string filename;
	switch(iSongSelection){
		case 0:		filename = "//home/pi/ECE4970/MidiFiles/_HarryPotter.mid.txt"; 		break;
		case 1:		filename = "//home/pi/ECE4970/MidiFiles/_Star_Wars_Theme.mid.txt";	break;
		default: 	filename = "//home/pi/ECE4970/MidiFiles/_Star_Wars_Theme.mid.txt";	break;
	}
    read.open(filename.data(), std::fstream::in);
	
	// Get data from file and put into SongLine vector
	NoteDurationPair thisPair;
    while(!read.eof()){
		getline(read, thisPair.Note, ' ');
		getline(read, currentString, '\n');

 		std::replace( thisPair.Note.begin(), thisPair.Note.end(), '\n', ' ');
		std::replace( currentString.begin(), currentString.end(), '\n', ' ');

		thisPair.iDuration = std::stoi(currentString);

		if(thisPair.Note.size() > 1) {
			SongLine.push_back(thisPair);
			// Print to screen to show accurate song file reading
			std::cout << thisPair.Note << "\t";
        	std::cout << thisPair.iDuration << std::endl;
		}
	}
	std::cout << std::endl;
    read.close();
	bNoteOrSong = false;
}

Song::Song(std::string Note){
	thisNote = Note;
	bNoteOrSong = true;
}

Song::~Song(){

}

void Song::Play(SoundPlayer* g_pSpeaker){
	int iSongLength = SongLine.size();
	bPlayingOrPaused = true;
	// Play line by line
	if(bNoteOrSong){
		while(1){
			// Check if the note was paused in different thread
			if(bPlayingOrPaused){			
				g_pSpeaker->PlayNote(
					ConvertCharsToNoteFrequency(thisNote,0), 
					1*NUMBER_OF_BEATS, false);
			}
			else
				break;
		}
	}
	else{
		for(int i = 0; i < iSongLength; i++) {
			// Check if the song was paused in different thread
			if(bPlayingOrPaused){			
				g_pSpeaker->PlayNote(
					ConvertCharsToNoteFrequency(SongLine[i].Note,0), 
					SongLine[i].iDuration*NUMBER_OF_BEATS);
			}
			else
				break;
		}
	}
	
}

void Song::Pause(){
	bPlayingOrPaused = false;
}
