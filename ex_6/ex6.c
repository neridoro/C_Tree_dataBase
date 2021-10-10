/***********
* Neria Doron
* 315351445
* 01
* ex6
***********/
#include "ex6.h"
#include "queue.h"
#include "Utils.h"
#define SPACE_NUMBER 3
//declarations
int familyExist(Trin_Ari* trin);
Trin_Ari* find_in_bin_tree(Trin_Ari* root, int* val);
void createQNode(void* index, QNode* qNod, Queue* q);
void printSecondMenu();
void printBidud(Trin_Ari* trin);
Trin_Ari* createTrinAriBody(char* name, int* id, Trin_Ari* trin);
void createTrinAriBranch(char* name, int* findId, Trin_Ari* trin, Trin_Ari* currentTrin, QNode* qNod, Queue* q);
void deleteTrinAriBranch(Trin_Ari* vaccinated, Trin_Ari* root);
void printMenu();
void initialize(QNode* qNod, Queue* q, Trin_Ari* trin);
void switchOfAllOption(QNode* headQnod, Queue* headq, Trin_Ari* headTrin, char fullinput[MAX_CHOISE_INPUT]);
void switchOptionOne(QNode* qNod, Queue* q, Trin_Ari* trin);
void switchOptionTwo(QNode* qNod, Queue* q, Trin_Ari* trin);
void switchOptionTree(Trin_Ari* trin);
void switchOptionFour(Trin_Ari* trin);
void switchOptionFive(Trin_Ari* trin);
void switchOptionSix(Trin_Ari* trin);
void makeMeFree(Trin_Ari* trin, QNode* qNod, Queue* q);

/******************
* Function familyExist:
* Input:Trin_Ari* root
* Output:true or false 1 or 0
* Function Operation:check if family exist
******************/
int familyExist(Trin_Ari* trin) {
    if (trin->id == 0 && trin!=NULL) {
        printf("Please create the family first\n");
        return 0;
    }
    return 1;
}
/******************
* Function find_in_bin_tree:
* Input:Trin_Ari* root,int* val
* Output:pointer to trin or null
* Function Operation:check if trin with given id is exist if so return it.
******************/
Trin_Ari* find_in_bin_tree(Trin_Ari* root, int* val) {
    Trin_Ari* tempPointer;
    if (root == NULL) {
        return NULL;
    }
    if (root->id == *val) {
        return root;
    }
    tempPointer=find_in_bin_tree(root->left,val);
    if (tempPointer == NULL) {
        tempPointer = find_in_bin_tree(root->middle, val);
        if (tempPointer == NULL) {
            tempPointer = find_in_bin_tree(root->right, val);
            if (tempPointer == NULL) {
                return NULL;
            }
        }
    }
    return tempPointer;
}
/******************
* Function: printMenu
* Input:
* Output:
* Function Operation:print the main menu
******************/
void printMenu() {
    printf("Please select an operation:\n"
        "\t0. Exit.\n"
        "\t1. Create family.\n"
        "\t2. Add family member.\n"
        "\t3. Print Family-Tree.\n"
        "\t4. Bidud.\n"
        "\t5. Superspreader.\n"
        "\t6. Vaccine.\n"
        "\t7. Print the menu.\n");
}
/******************
* Function:printSecondMenu
* Input:
* Output:
* Function Operation:print the print second menu
******************/
void printSecondMenu() {
    printf("Please select an operation:\n"
        "\t0. Return to the main menu.\n"
        "\t1. Print Trin-Ari family.\n"
        "\t2. Print Pre-order.\n"
        "\t3. Print Left-order.\n"
        "\t4. Print BFS.\n");
}
/******************
* Function:printBidud
* Input:Trin_Ari* trin
* Output:
* Function Operation:print person in bidud
******************/
void printBidud(Trin_Ari* trin){
    if (trin != NULL && trin->id != 0) {
        printf("#StayHome! %s %d\n", trin->name, trin->id);
    }
}
/******************
* Function:initialize
* Input:QNode* qNod, Queue* q, Trin_Ari* trin
* Output:
* Function Operation:initiate all needed struct with null.
******************/
void initialize(QNode* qNod, Queue* q, Trin_Ari* trin) {
    qNod->key = NULL;
    qNod->next = NULL;
    q->front = NULL;
    q->rear = NULL;
    trin->id = 0;
    trin->name = NULL;
    trin->left = NULL;
    trin->right = NULL;
    trin->middle = NULL;
    trin->father = NULL;
}
/******************
* Function:createTrinAriBody
* Input:char* name, int* id, Trin_Ari* trin
* Output:pointer to newly created trin
* Function Operation:create new body trin
******************/
Trin_Ari* createTrinAriBody(char* name, int* id, Trin_Ari* trin) {
    Trin_Ari* bodyTrin = malloc(sizeof(Trin_Ari));
    bodyTrin->id = *id;
    bodyTrin->name = name;
    bodyTrin->left = NULL;
    bodyTrin->right = NULL;
    bodyTrin->middle = NULL;
    bodyTrin->father = trin;
    printf("Hello %s, ID: %d\n", bodyTrin->name, bodyTrin->id);
    return bodyTrin;
}
/******************
* Function:createTrinAriBranch
* Input:char* name, int* findId, Trin_Ari* trin, Trin_Ari* currentTrin, QNode* qNod, Queue* q
* Output:
* Function Operation:find the parent of the new branch and create new branch for parent
******************/
void createTrinAriBranch(char* name, int* findId, Trin_Ari* trin, Trin_Ari* currentTrin, QNode* qNod, Queue* q){
    //find the needed trin
    Trin_Ari* existTrin = find_in_bin_tree(trin, findId);
    //put the new trin in the currect order of creation (left mid then right)
    if (existTrin == NULL) {
        if (currentTrin->left == NULL) {
            currentTrin->left = createTrinAriBody(name, findId, currentTrin);
        }
        else if (currentTrin->middle == NULL) {
            currentTrin->middle = createTrinAriBody(name, findId, currentTrin);
        }
        else if (currentTrin->right == NULL) {
            currentTrin->right = createTrinAriBody(name, findId, currentTrin);
        }
        //save my inputs in new stuct
        createQNode(name, qNod, q);
        createQNode(findId, qNod, q);
    }
    //not good id try new one
    else {
        printf("ID %d belongs to %s\n", existTrin->id, existTrin->name);
        printf("enter name\n");
        fgets(name, MAX_NAME, stdin);
        name[strlen(name) - 1] = '\0';
        printf("enter ID\n");
        scanf("%d", findId);
        char destroy[2];
        fgets(destroy, sizeof(destroy), stdin);
        createTrinAriBranch(name, findId, trin, currentTrin, qNod, q);
    }
}
/******************
* Function:deleteTrinAriBranch
* Input:Trin_Ari* vaccinated,Trin_Ari* root
* Output:
* Function Operation:delete all sub branches of given vaccinated trin
******************/
void deleteTrinAriBranch(Trin_Ari* vaccinated,Trin_Ari* root) {
    if (vaccinated->left != NULL) {
        deleteTrinAriBranch(vaccinated->left,root);
    }
    if (vaccinated->middle != NULL) {
        deleteTrinAriBranch(vaccinated->middle,root);
    }
    if (vaccinated->right != NULL) {
        deleteTrinAriBranch(vaccinated->right,root);
    }
    printf("%s ID: %d Survived!\n", vaccinated->name, vaccinated->id);
    if (vaccinated != root){
        if (vaccinated->father->left == vaccinated) {
            vaccinated->father->left = NULL;
        }
        else if (vaccinated->father->middle == vaccinated) {
            vaccinated->father->middle = NULL;
        }
        else if (vaccinated->father->right == vaccinated) {
            vaccinated->father->right = NULL;
        }
        free(vaccinated);
    }
    //if its the head tree just make it null and wait for re creation.
    else {
        vaccinated->name = NULL;
        vaccinated->id = 0;
    }
}
/******************
* Function:switchOfAllOption
* Input:QNode* headQnod, Queue* headq, Trin_Ari* headTrin, char fullinput[MAX_CHOISE_INPUT]
* Output:
* Function Operation:send to needed function depens on input
******************/
void switchOfAllOption(QNode* headQnod, Queue* headq, Trin_Ari* headTrin, char fullinput[MAX_CHOISE_INPUT]) {
    switch (*fullinput){
    case '1': {
        switchOptionOne(headQnod, headq, headTrin);
        printf("Select the next operation (insert 7 for the entire menu):\n");
        break;
    }
    case '2': {
        switchOptionTwo(headQnod, headq, headTrin);
        printf("Select the next operation (insert 7 for the entire menu):\n");
        break;
    }
    case '3': {
        switchOptionTree(headTrin);
        break;
    }
    case '4': {
        switchOptionFour(headTrin);
        printf("Select the next operation (insert 7 for the entire menu):\n");
        break;
    }
    case '5': {
        switchOptionFive(headTrin);
        printf("Select the next operation (insert 7 for the entire menu):\n");
        break;
    }
    case '6': {
        switchOptionSix(headTrin);
        printf("Select the next operation (insert 7 for the entire menu):\n");
        break;
    }
    case '7': {
        printMenu();
        break;
    }
    default: {
        printf("Error: unrecognized operation.\n");
        printf("Select the next operation (insert 7 for the entire menu):\n");
    }
    }
}
/******************
* Function:switchOptionOne
* Input:QNode* qNod, Queue* q, Trin_Ari* trin
* Output:
* Function Operation:create new family
******************/
void switchOptionOne(QNode* qNod, Queue* q, Trin_Ari* trin) {
    char* name = malloc(MAX_NAME);
    int *id= malloc(sizeof(int));
    char destroy[2];
    if (name == NULL || id==NULL) {
        exit(1);
    }
    if (trin->id == 0) {
        printf("enter name\n");
        fgets(name, MAX_NAME, stdin);
        name[strlen(name) - 1] = '\0';
        printf("enter ID\n");
        scanf("%d",id);
        trin->id = *id;
        trin->name = name;
        createQNode(name, qNod, q);
        createQNode(id, qNod, q);
        //destroy the new line from buffer
        fgets(destroy, sizeof(destroy), stdin);
        printf("Hello %s, ID: %d\n", trin->name, trin->id);
    }
    else {
        free(id);
        free(name);
        printf("The family has already been created\n");
    }
}
/******************
* Function:switchOptionTwo
* Input:QNode* qNod, Queue* q, Trin_Ari* trin
* Output:
* Function Operation:create another branch in tree
******************/
void switchOptionTwo(QNode* qNod, Queue* q, Trin_Ari* trin) {
    if (familyExist(trin) == 1) {
        int* findId = malloc(sizeof(int));
        printf("Enter the ID of the person who wants to make an appointment?\n");
        scanf("%d", findId);
        char destroy[2];
        fgets(destroy, sizeof(destroy), stdin);
        Trin_Ari* currentTrin = find_in_bin_tree(trin, findId);
        if (currentTrin == NULL) {
            printf("There is no ID %d\n", *findId);
            free(findId);
            
        }
        else if(currentTrin->left == NULL ||
            currentTrin->middle == NULL ||
            currentTrin->right == NULL){
            char* name = malloc(MAX_NAME);
            printf("enter name\n");
            fgets(name, MAX_NAME, stdin);
            name[strlen(name) - 1] = '\0';
            printf("enter ID\n");
            scanf("%d", findId);
            fgets(destroy, 2, stdin);
            createTrinAriBranch(name, findId, trin, currentTrin,qNod,q);
        }
        else {
            printf("%s ID: %d can't meet more than 3 members!\n", currentTrin->name, currentTrin->id);
            free(findId);
        }
    }
}
/******************
* Function:switchOptionTree
* Input:Trin_Ari* trin
* Output:
* Function Operation:print tree in several options
******************/
void switchOptionTree(Trin_Ari* trin) {
    printSecondMenu();
    char fullinput[MAX_CHOISE_INPUT];
    fgets(fullinput, MAX_CHOISE_INPUT, stdin);
    switch (*fullinput) {
    case '0': {
        printMenu();
        break;
    }
    case '1': {
        if (trin->id != 0) {
            print2DUtil(trin,SPACE_NUMBER);
        }
        printMenu();
        break;
    }
    case '2': {
        if (trin->id != 0) {
            preOrder(trin);
        }
        printMenu();
        break;
    }
    case '3': {
        if (trin->id != 0) {
            leftOrder(trin);
        }
        printMenu();
        break;
    }
    case '4': {
        if (trin->id != 0) {
            printLevelOrder(trin, 0);
        }
        printMenu();
        break;
    }
    default: {
        printf("Error: unrecognized operation.\n");
        switchOptionTree(trin);
    }
    }
}
/******************
* Function:switchOptionFour
* Input:Trin_Ari* trin
* Output:
* Function Operation:send given id to bidud with parent and the 3 children
******************/
void switchOptionFour(Trin_Ari* trin) {
    if (familyExist(trin) == 1){
        int* findId = malloc(sizeof(int));
        printf("Enter the ID of the suspected member\n");
        scanf("%d", findId);
        char destroy[2];
        fgets(destroy, sizeof(destroy), stdin);
        Trin_Ari* Bidud = find_in_bin_tree(trin, findId);
        if (Bidud == NULL) {
            printf("ID %d does not exist\n", *findId);
        }
        else {
            printBidud(Bidud->father);
            printBidud(Bidud);
            printBidud(Bidud->left);
            printBidud(Bidud->middle);
            printBidud(Bidud->right);
        }
        free(findId);
    }
}
/******************
* Function:switchOptionFive
* Input:Trin_Ari* trin
* Output:
* Function Operation:send given id to bidud with all children
******************/
void switchOptionFive(Trin_Ari* trin) {
    if (familyExist(trin) == 1) {
        int* findId = malloc(sizeof(int));
        printf("Enter the ID of the suspected Superspreader\n");
        scanf("%d", findId);
        char destroy[2];
        fgets(destroy, sizeof(destroy), stdin);
        Trin_Ari* spreader = find_in_bin_tree(trin, findId);
        if (spreader == NULL) {
            printf("ID %d does not exist\n", *findId);
        }
        else {
            if (spreader->father != NULL) {
                printf("#StayHome! %s %d\n", spreader->father->name, spreader->father->id);
            }
            printLevelOrder(spreader, 1);
        }
        free(findId);
    }
}
/******************
* Function:switchOptionSix
* Input:Trin_Ari* trin
* Output:
* Function Operation:delete trin id and all his children
******************/
void switchOptionSix(Trin_Ari* trin) {
    if (familyExist(trin) == 1) {
        int* findId = malloc(sizeof(int));
        printf("Who got vaccinated (ID)?\n");
        scanf("%d", findId);
        char destroy[2];
        fgets(destroy, sizeof(destroy), stdin);
        Trin_Ari* vaccinated = find_in_bin_tree(trin, findId);
        if (vaccinated == NULL) {
            printf("There is no ID %d\n", *findId);
        }
        else if (vaccinated->father != NULL) {
            if (vaccinated->father->left == vaccinated) {
                vaccinated->father->left = NULL;
            }
            else if (vaccinated->father->middle == vaccinated) {
                vaccinated->father->middle = NULL;
            }
            else if (vaccinated->father->right == vaccinated) {
                vaccinated->father->right = NULL;
            }
            deleteTrinAriBranch(vaccinated, trin);
        }
        else{
            deleteTrinAriBranch(vaccinated, trin);
        }
        free(findId);
    }
}
/******************
* Function:makeMeFree
* Input:Trin_Ari* trin, QNode* qNod, Queue* q
* Output:
* Function Operation:free all structs created and make me free.
******************/
void makeMeFree(Trin_Ari* trin, QNode* qNod, Queue* q) {
    if (trin->id != 0) {
        deleteTrinAriBranch(trin, trin);
    }
    free(trin);
    free(q);
    QNode* temp;
    while (qNod != NULL) {
        temp = qNod;
        qNod = qNod->next;
        free(temp->key);
        free(temp);
    }
}
/******************
* Function:createQNode
* Input:void* index, QNode* qNod, Queue* q
* Output:
* Function Operation:save input in struct so i can remove it easy later.
******************/
void createQNode(void* index, QNode* qNod, Queue* q) {
    if (qNod->key == NULL) {
        qNod->key = index;
        q->front = q->rear = qNod;
    }
    else {
        QNode* qBody = malloc(sizeof(QNode));
        q->rear->next = qBody;
        qBody->key = index;
        qBody->next = NULL;
        q->rear = qBody;
    }

}