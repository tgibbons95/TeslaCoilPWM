#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * 
 */
void ModifyString(std::string &line, bool bIsFirstLine);

int main(int argc, char** argv) {

    if(argc != 2){
        std::cout << "Usage: " << argv[0] << " <midi.txt file>" << std::endl;
        return 1;
    }
    
    // Storage for Write back
    std::vector<string> NoteAndDurationPairs;
    std::string currentString;
    std::string fileName = argv[1];
    
    // Open files
    std::fstream read;
    std::fstream write;
    read.open(fileName.data(), std::fstream::in);
    fileName.insert(0, 1, '_');
    write.open(fileName.data(), std::fstream::out);
    if(!read.eof()){
		getline(read, currentString, ';');
		ModifyString(currentString, true);
        write <<  currentString << std::endl;
        std::cout << currentString << std::endl;
	}

    while(!read.eof()){
        getline(read, currentString, ';');
		ModifyString(currentString, true);
        write <<  currentString << std::endl;
        std::cout << currentString << std::endl;
    }
    
    read.close();
    write.close();
    
    return 0;
}

void ModifyString(std::string &line, bool bIsFirstLine){
	if(line.length() < 5) {
		line = "";
		return;
	}
	if(bIsFirstLine){
		line.erase(line.begin(),line.begin() + line.find('|') + 1);
		line.erase(line.begin(),line.begin() + line.find('|') + 1);
	}
	line.erase(line.begin(),line.begin() + line.find(' ') + 1);
	line.erase(line.end() - 2, line.end());

}
