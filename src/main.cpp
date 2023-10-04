#include <iostream>
#include "./drivers/StateMachine.cpp"

using namespace std;

int main(){
	
    StateMachine vendingMachine;

    while(1){
		vendingMachine.nextStateLogic();
    }

    return 0;
}


