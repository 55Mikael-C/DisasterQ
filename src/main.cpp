#include <iostream>
#include "coordinator.h"
#include "priority_queue.h"
#include "queue.h"
#include "stack.h"
#include "victim.h"


using namespace std;

int main(){

    Stack dispatchLog;
    PriorityQueue criticalQueue;
    Queue standardQueue;

    int arrivalCounter = 0;

    bool isActive = true;
    while(isActive){
        int choice = selectMenu();
        switch(choice){
            case 1: reportVictim(criticalQueue, standardQueue, arrivalCounter); break; 
            case 2: dispatchRescue(dispatchLog, criticalQueue, standardQueue); break; 
            case 3: break; //displayQueues()
            case 4: break; //searchVictim()
            case 5: dispatchLog.display(); break;
            case 6: isActive = false; break; //exit
        };
    };
    
    
    return 0;
}