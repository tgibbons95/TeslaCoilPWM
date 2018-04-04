#include "Headers/Notes.h"

int HandleA(std::string szCommand, int iPosition){
	int iRet = 0;	
	switch(szCommand[iPosition]){
		case '0': iRet = A0;	break;
		case '1': iRet = A1;	break;
		case '2': iRet = A2;	break;
		case '3': iRet = A3;	break;
		case '4': iRet = A4;	break;
		case '5': iRet = A5;	break;
		case '6': iRet = A6;	break;
		case '7': iRet = A7;	break;
		case '#': 
			if((int)szCommand.size() > iPosition + 1) {
				switch(szCommand[iPosition + 1]){
					case '0': iRet = A_sharp0;	break;
					case '1': iRet = A_sharp1;	break;
					case '2': iRet = A_sharp2;	break;
					case '3': iRet = A_sharp3;	break;
					case '4': iRet = A_sharp4;	break;
					case '5': iRet = A_sharp5;	break;
					case '6': iRet = A_sharp6;	break;
					case '7': iRet = A_sharp7;	break;
					default: iRet = -1;		break;
				}
			}
			else {
				iRet = -1;
			}
			break;
		default: iRet = -1;	break;
	}
	return iRet;
}

int HandleB(std::string szCommand, int iPosition){
	int iRet = 0;	
	switch(szCommand[iPosition]){
		case '0': iRet = B0;	break;
		case '1': iRet = B1;	break;
		case '2': iRet = B2;	break;
		case '3': iRet = B3;	break;
		case '4': iRet = B4;	break;
		case '5': iRet = B5;	break;
		case '6': iRet = B6;	break;
		case '7': iRet = B7;	break;
		default: iRet = -1;	break;
	}
	return iRet;
}

int HandleC(std::string szCommand, int iPosition){
	int iRet = 0;	
	switch(szCommand[iPosition]){
		case '1': iRet = C1;	break;
		case '2': iRet = C2;	break;
		case '3': iRet = C3;	break;
		case '4': iRet = C4;	break;
		case '5': iRet = C5;	break;
		case '6': iRet = C6;	break;
		case '7': iRet = C7;	break;
		case '8': iRet = C8;	break;
		case '#': 
			if((int)szCommand.size() > iPosition + 1) {
				switch(szCommand[iPosition + 1]){
					case '1': iRet = C_sharp1;	break;
					case '2': iRet = C_sharp2;	break;
					case '3': iRet = C_sharp3;	break;
					case '4': iRet = C_sharp4;	break;
					case '5': iRet = C_sharp5;	break;
					case '6': iRet = C_sharp6;	break;
					case '7': iRet = C_sharp7;	break;
					default: iRet = -1;		break;
				}
			}
			else {
				iRet = -1;
			}
			break;
		default: iRet = -1;	break;
	}
	return iRet;
}

int HandleD(std::string szCommand, int iPosition){
	int iRet = 0;	
	switch(szCommand[iPosition]){
		case '1': iRet = D1;	break;
		case '2': iRet = D2;	break;
		case '3': iRet = D3;	break;
		case '4': iRet = D4;	break;
		case '5': iRet = D5;	break;
		case '6': iRet = D6;	break;
		case '7': iRet = D7;	break;
		case '#': 
			if((int)szCommand.size() > iPosition + 1) {
				switch(szCommand[iPosition + 1]){
					case '1': iRet = D_sharp1;	break;
					case '2': iRet = D_sharp2;	break;
					case '3': iRet = D_sharp3;	break;
					case '4': iRet = D_sharp4;	break;
					case '5': iRet = D_sharp5;	break;
					case '6': iRet = D_sharp6;	break;
					case '7': iRet = D_sharp7;	break;
					default: iRet = -1;		break;
				}
			}
			else {
				iRet = -1;
			}
			break;
		default: iRet = -1;	break;
	}
	return iRet;
}

int HandleE(std::string szCommand, int iPosition){
	int iRet = 0;	
	switch(szCommand[iPosition]){
		case '1': iRet = E1;	break;
		case '2': iRet = E2;	break;
		case '3': iRet = E3;	break;
		case '4': iRet = E4;	break;
		case '5': iRet = E5;	break;
		case '6': iRet = E6;	break;
		case '7': iRet = E7;	break;
		default: iRet = -1;	break;
	}
	return iRet;
}

int HandleF(std::string szCommand, int iPosition){
	int iRet = 0;	
	switch(szCommand[iPosition]){
		case '1': iRet = F1;	break;
		case '2': iRet = F2;	break;
		case '3': iRet = F3;	break;
		case '4': iRet = F4;	break;
		case '5': iRet = F5;	break;
		case '6': iRet = F6;	break;
		case '7': iRet = F7;	break;
		case '#': 
			if((int)szCommand.size() > iPosition + 1) {
				switch(szCommand[iPosition + 1]){
					case '1': iRet = F_sharp1;	break;
					case '2': iRet = F_sharp2;	break;
					case '3': iRet = F_sharp3;	break;
					case '4': iRet = F_sharp4;	break;
					case '5': iRet = F_sharp5;	break;
					case '6': iRet = F_sharp6;	break;
					case '7': iRet = F_sharp7;	break;
					default: iRet = -1;		break;
				}
			}
			else {
				iRet = -1;
			}
			break;
		default: iRet = -1;	break;
	}
	return iRet;
}

int HandleG(std::string szCommand, int iPosition){
	int iRet = 0;	
	switch(szCommand[iPosition]){
		case '1': iRet = G1;	break;
		case '2': iRet = G2;	break;
		case '3': iRet = G3;	break;
		case '4': iRet = G4;	break;
		case '5': iRet = G5;	break;
		case '6': iRet = G6;	break;
		case '7': iRet = G7;	break;
		case '#': 
			if((int)szCommand.size() > iPosition + 1) {
				switch(szCommand[iPosition + 1]){
					case '1': iRet = G_sharp1;	break;
					case '2': iRet = G_sharp2;	break;
					case '3': iRet = G_sharp3;	break;
					case '4': iRet = G_sharp4;	break;
					case '5': iRet = G_sharp5;	break;
					case '6': iRet = G_sharp6;	break;
					case '7': iRet = G_sharp7;	break;
					default: iRet = -1;		break;
				}
			}
			else {
				iRet = -1;
			}
			break;
		default: iRet = -1;	break;
	}
	return iRet;
}

int ConvertCharsToNoteFrequency(std::string szCommand, int iPosition) {
	int iRet = 0;
	switch(szCommand[iPosition]){
		case 'A': iRet = HandleA(szCommand, iPosition + 1); break;
		case 'B': iRet = HandleB(szCommand, iPosition + 1); break;
		case 'C': iRet = HandleC(szCommand, iPosition + 1); break;
		case 'D': iRet = HandleD(szCommand, iPosition + 1); break;
		case 'E': iRet = HandleE(szCommand, iPosition + 1); break;
		case 'F': iRet = HandleF(szCommand, iPosition + 1); break;
		case 'G': iRet = HandleG(szCommand, iPosition + 1); break;
		default: iRet = -1;
	}
	return iRet;
}
