/* 
  LEDs LD0 to LD5 are mapped to GPIO bits 0 to 5.
  Switches SW0 to SW5 are mapped to GPIO bits 8 to 13.
  Buttons BTNU, BTNL, BTND, BTNR, BTNC are mapped to GPIO bits 16 to 20.
  The PMODA port is mapped to GPIO bits 24 to 31.
  
*/

#include <iostream>
#include <InputSignals.h>
using namespace std;

class Interface {
    protected:
        volatile unsigned int *readAddress = (volatile unsigned int *)0x80000a00;
        volatile unsigned int *outputAddress = (volatile unsigned int *)0x80000a04;
		int inputChoice;
		InputSignals input;
	public:
		InputSignals getInput();
		void init();
        void returnMoney(int amount);
		void lEtirps();
		void lMeet();
};