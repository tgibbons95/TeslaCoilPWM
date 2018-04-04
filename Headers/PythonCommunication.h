#include "pthread.h"

class PythonCommunication{

	public:
		PythonCommunication();
		int getSelection();

	protected:
	
	private:
		int iPipeValue;
		pthread_t CommunicationThread;
};

void* Communicate(void* data);
