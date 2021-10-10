/***********
* Neria Doron
* 315351445
* 01
* ex6
***********/
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include <stdio.h>
#ifndef _EX6_H_
#define _EX6_H_
#define MAX_CHOISE_INPUT 3
#define MAX_NAME 50
#include"queue.h"


struct Trin_Ari {
	int id;
	char* name;
	struct Trin_Ari* left;
	struct Trin_Ari* middle;
	struct Trin_Ari* right;
	struct Trin_Ari* father;
};
//declarations
typedef struct Trin_Ari Trin_Ari;
void printMenu();
void initialize(QNode* qNod, Queue* q, Trin_Ari* trin);
void switchOfAllOption(QNode* headQnod, Queue* headq, Trin_Ari* headTrin, char fullinput[MAX_CHOISE_INPUT]);
void makeMeFree(Trin_Ari* trin, QNode* qNod, Queue* q);

#endif
