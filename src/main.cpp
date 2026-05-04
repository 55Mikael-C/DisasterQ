#include <iostream>
#include "coordinator.h"
#include "stack.h"
#include "victim.h"

using namespace std;

int main(){

    Stack dispatchLog;

    bool isActive = true;
    while(isActive){
        int choice = selectMenu();
        switch(choice){
            case 1: break; //reportVictim()
            case 2: break; //dispatchRescue()
            case 3: break; //displayQueues()
            case 4: break; //searchVictim()
            case 5: dispatchLog.display(); break;
            case 6: isActive = false; break; //exit
        };
    };
    
    
    return 0;
}