/***********
* Neria Doron
* 315351445
* 01
* ex6
***********/
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "ex6.h"
// A linked list (LL) node to store a queue entry 
typedef struct QNode {
	void* key;
	struct QNode* next;
}QNode;

// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
typedef struct Queue {
	struct QNode* front, * rear;
}Queue;
//declarations
void createQNode(void* index, QNode* qNod, Queue* q);
#endif
