#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "priority_queue.h"
#include "queue.h"
#include "stack.h"

std::string generateID(int num);
int selectMenu();
void reportVictim(PriorityQueue& criticalQueue, Queue& standardQueue, int& counter);
void dispatchRescue(Stack& dispatchLog, PriorityQueue& criticalQueue, Queue& standardQueue);
void displayQueues(PriorityQueue& criticalQueue, Queue& standardQueue);
void searchVictim();
#endif