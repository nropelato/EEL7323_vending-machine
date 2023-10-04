#include "../includes/Interface.h"

void Interface::init(){
	*outputAddress = 0x00000000;
}

/*
---------- INPUT MAPS -----------
DEV    -> SW5      D025    -> LD4
M025   -> SW4      D050    -> LD3
M050   -> SW3      D100    -> LD2
M100   -> SW2      LETIRPS -> LD1
MEET   -> SW1      LMEET   -> LD0
ETIRPS -> SW0
*/

void Interface::returnMoney(int amount){
	switch(amount){
		case 25:
			*outputAddress = 0x00000010;
			break;
		case 50:
			*outputAddress = 0x00000008;
			break;
		case 75:
			*outputAddress = 0x00000018;
			break;
		case 100:
			*outputAddress = 0x00000004;
			break;
		case 125:
			*outputAddress = 0x00000014;
			break;
		case 150:
			*outputAddress = 0x0000000c;
			break;
    }
}

InputSignals Interface::getInput(){
	switch(*readAddress){
		case 0x00000020:
			input = InputSignals::DEV;
			break;
		case 0x00000010:
			input = InputSignals::M025;
			break;
		case 0x00000008:
			input = InputSignals::M050;
			break;
		case 0x00000004:
			input = InputSignals::M100;
			break;
		case 0x00000002:
			input = InputSignals::MEET;
			break;
		case 0x00000001:
			input = InputSignals::ETIRPS;
			break;
    }
}

void Interface::lEtirps(){
	*outputAddress = 0x00000002;
}

void Interface::lMeet(){
	*outputAddress = 0x00000001;
}