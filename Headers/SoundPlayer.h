#include "Notes.h"

class SoundPlayer{

	public:
		SoundPlayer();
		SoundPlayer(int iSpeakerGpioPin, bool bUseKernel);
		~SoundPlayer();
		void PlayNoteIndefinitely( int Note);
		void PlayNote(unsigned int Note, int iAmountOfTimesToPlay, bool bUseDelay = true);
		void SlightPause();
	protected:
	
	private:
		void Error(const char*);		
		void SetupConnections();
		int iSpeakerGpioPin;
		int cdev_id;
		std::string ErrorMessage;
		bool bUseKernel;

};
