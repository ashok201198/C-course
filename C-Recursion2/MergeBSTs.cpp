/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
	Example 1:

	Input :
	20        25
	/  \      /  \
	5    30   10   35
	Output :

	Bst 1 :
	20
	/   \
	5     30
	\   /  \
	10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};
void add(struct BstNode *root1, int k,struct BstNode *temp,int *i)
{
	if (root1 != NULL){
		if ((root1)->data == k)
		{
			(*i) = 1; 
			return; 
		}
		else if (k>(root1)->data )
		{
			add(root1->right, k,temp,i);
			//struct BstNode * temp = (struct BstNode *)malloc(sizeof(struct BstNode));
			if (*i == 0){
				
				root1->right = temp;
				root1->right->left = NULL;
				root1->right->right = NULL;
				(*i) = 1;
			}
			return;
		}
		else if (k<(root1)->data)
		{
			add(root1->left, k,temp,i);
			//struct BstNode * temp = (struct BstNode *)malloc(sizeof(struct BstNode));
			if (*i == 0)
			{
				(root1)->left = temp;
				root1->left->left = NULL;
				root1->left->right = NULL;
				(*i) = 1;
			}
			return;
		}
	}
	else
	{
		
	}
}
void call(struct BstNode **root1, struct BstNode *root2)
{
	if (root2 != NULL)
	{
		call(root1, root2->left);
		call(root1, root2->right);
		int k = root2->data;
		int i = 0;
		add(*root1, k, root2, &i);
	}
}
void merge_two_bst(struct BstNode **root1, struct BstNode *root2) 
{
	if (root2 == NULL)
	{
		return; 
	}
	else if (*root1 == NULL)
	{
		* root1 = (struct BstNode *)malloc(sizeof(struct BstNode));
		/*(*root1)->data = root2->data;
		(*root1)->left = NULL;
		(*root1)->right = NULL;*/
		(*root1) = root2;
	}
	else call(root1, root2);
}