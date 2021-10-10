/***********
* Neria Doron
* 315351445
* 01
* ex6
***********/
#include "ex6.h"
#include "queue.h"
#include "Utils.h"

int main() {
	char fullinput[MAX_CHOISE_INPUT];
	printMenu();
	fgets(fullinput, MAX_CHOISE_INPUT, stdin);
	QNode* headQnod = malloc(sizeof(QNode));
	Queue* headq = malloc(sizeof(Queue));
	Trin_Ari* headTrin= malloc(sizeof(Trin_Ari));
	initialize(headQnod,headq, headTrin);
	while (*fullinput != '0') {
		switchOfAllOption(headQnod, headq, headTrin, fullinput);
		fgets(fullinput, MAX_CHOISE_INPUT, stdin);
	}
	makeMeFree(headTrin, headQnod, headq);
}