#include <iostream>
#include "./src/drivers/StateMachine.cpp"

using namespace std;

int main(){
	
    StateMachine vendingMachine;

    while(1){
		vendingMachine.nextStateLogic();
    }

    return 0;
}


