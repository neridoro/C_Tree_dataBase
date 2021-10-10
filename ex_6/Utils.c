/***********
* Neria Doron
* 315351445
* 01
* ex6
***********/
#include <stdio.h>
#include "Utils.h"
#define COUNT 8

// Function to print Trinary tree in 2D 
// It does reverse inorder traversal 

/******************
* Function print2DUtil:
* Input:Trin_Ari* root, int space
* Output:NULL
* Function Operation:print the tree in 2d
******************/
void print2DUtil(Trin_Ari* root, int space)
{
	// Base case 
	if (root == NULL)
		return;

	// Increase distance between levels 
	space += COUNT;

	// Process right child first 
	print2DUtil(root->right, space);
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%s %d\n", root->name, root->id);
	// Process middle child 
	print2DUtil(root->middle, space);
	printf("\n");
	// Process left child 
	print2DUtil(root->left, space);
}
/******************
* Function: preOrder
* Input:Trin_Ari* root
* Output:NULL
* Function Operation:print items in tree in pre order way
******************/
void preOrder(Trin_Ari* root) {
	if (root != NULL) {
		printf("%s ID: %d\n", root->name, root->id);
		preOrder(root->left);
		preOrder(root->middle);
		preOrder(root->right);
	}
}
/******************
* Function: leftOrder
* Input:Trin_Ari* root
* Output:NULL
* Function Operation:print items in tree in left order way
******************/
void leftOrder(Trin_Ari* root) {
	if (root == NULL) {
		return;
	}
	leftOrder(root->left);
	printf("%s ID: %d\n", root->name, root->id);
	leftOrder(root->middle);
	leftOrder(root->right);
}
/******************
* Function :printLevelOrder
* Input:Trin_Ari* root,int option
* Output:NULL
* Function Operation:print int BFS order
* * (the option is for another print option in the procces)
******************/
void printLevelOrder(Trin_Ari* root,int option)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i,option);
}
/******************
* Function :printGivenLevel
* Input:Trin_Ari* root, int level,int option
* Output:NULL
* Function Operation:print my current level
* (the option is for another print option in the procces)
******************/
void printGivenLevel(Trin_Ari* root, int level,int option)
{
    if (root == NULL)
        return;
    if (level == 1) {
        if (option == 1) {
            printf("#StayHome! %s %d\n", root->name, root->id);
        }
        else {
            printf("%s %d\n", root->name, root->id);
        }
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1,option);
        printGivenLevel(root->middle, level - 1,option);
        printGivenLevel(root->right, level - 1,option);
    }
}
/******************
* Function :height
* Input:Trin_Ari* root
* Output:NULL
* Function Operation:find longest branch
******************/
int height(Trin_Ari* root)
{
    if (root == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(root->left);
        int mheight = height(root->middle);
        int rheight = height(root->right);

        /* use the larger one */
        if (lheight >= rheight && lheight >= mheight)
            return(lheight + 1);
        if (mheight >= lheight && mheight >= rheight)
            return(mheight + 1);
        if (rheight >= lheight && rheight >= mheight)
            return(rheight + 1);
    }
}