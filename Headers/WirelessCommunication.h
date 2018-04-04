#include <string>
#include <netinet/in.h>

#define LOG_SIZE 40

class WirelessCommunication {

	public:
		// Methods
		std::string Receive();	
		int Send();

		// Constructors and destructor
		WirelessCommunication();
		WirelessCommunication(int data);
		~WirelessCommunication();	
	protected:
		
	private:
		void SetupConnections();
		void Error(const char*);		

		// Class data
		int iPortNumber;
		int iSocketFD;

		std::string czIPAddress;

		struct sockaddr_in server;
		int iLengthOfServer;
		
		struct sockaddr_in from;
		socklen_t iLengthOfFrom;

		struct sockaddr_in anybody;
		
		std::string ErrorMessage;
		std::string LastMessage;		
};
