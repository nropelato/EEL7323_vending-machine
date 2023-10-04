#include <iostream>
#include "States.h"
#include "InputSignals.h"
#include "../drivers/interface.cpp"

using namespace std;

class StateMachine {
    States state;
    public:
        StateMachine();
        ~StateMachine();
        Interface* system;
        void nextStateLogic();
};