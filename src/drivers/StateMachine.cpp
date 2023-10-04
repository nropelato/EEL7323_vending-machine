#include "../includes/StateMachine.h"

StateMachine::StateMachine(){
    state = States::S000;
    system = new Interface;
    system -> init();
}

StateMachine::~StateMachine(){
    delete system;
}

void StateMachine::nextStateLogic(){
    InputSignals input = system -> getInput();

    switch(state){
        case States::S000:
            if (input == InputSignals::M025) {
                state = States::S025;
            }
            else if (input == InputSignals::M050) {
                state = States::S050;
            }
            else if (input == InputSignals::M100) {
                state = States::S100;
            }
            break;
        case States::S025:
            if (input == InputSignals::DEV) {
                system -> returnMoney(25); 
                state = States::S000;
            }
            else if (input == InputSignals::M025){
                state = States::S050;
            }
            else if (input == InputSignals::M050) {
                state = States::S075;
            }
            else if (input == InputSignals::M100) {
                state = States::S125;
            }
            break;
        case States::S050:
            if (input == InputSignals::DEV) {
                system -> returnMoney(50); 
                state = States::S000;
            }
            else if (input == InputSignals::M025) {
                state = States::S075;
            }
            else if (input == InputSignals::M050) {
                state = States::S100;
            }
            else if (input == InputSignals::M100) {
                state = States::S150;
            }
            break;
        case States::S075:
            if (input == InputSignals::DEV) {
                system -> returnMoney(75);
                state = States::S000;
            }
            else if (input == InputSignals::M025) {
                state = States::S100;
            }
            else if (input == InputSignals::M050) {
                state = States::S125;
            }
            else if (input == InputSignals::M100) {
                state = States::S150;
            }      
            break;
        case States::S100:
            if (input == InputSignals::DEV) {
            	system -> returnMoney(100); 
                state = States::S000;
            }
            else if (input == InputSignals::M025) {
            	state = States::S125;
            }
            else if (input == InputSignals::M050) {
            	state = States::S150;
            }
            else if (input == InputSignals::M100) {
                system -> returnMoney(50);
            }
            break;
        case States::S125:
            if (input == InputSignals::DEV) {
            	system -> returnMoney(125); 
                state = States::S000;
            }
            else if (input == InputSignals::M025) {
            	state = States::S150;
            }
            else if (input == InputSignals::M050) {
                system -> returnMoney(25);             	
                state = States::S150;
            }
            else if (input == InputSignals::M100) {
                system -> returnMoney(75); 
                state = States::S150;
            }
            break;
        case States::S150:
            if (input == InputSignals::DEV) {
            	system -> returnMoney(150);           	
                state = States::S000;
            }
            else if (input == InputSignals::MEET) {
            	system -> lMeet();
                state = States::S000;
            }
            else if (input == InputSignals::ETIRPS) {
            	system -> lEtirps();
                state = States::S000;
            }            
            else if (input == InputSignals::M025) {
            	system -> returnMoney(25);
            }
            else if (input == InputSignals::M050) {
            	system -> returnMoney(50);
            }
            else if (input == InputSignals::M100) {
            	system -> returnMoney(100);
            }
            break;
        default:
            break;
    }
}