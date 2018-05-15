/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void getarr(struct node * root, int * a,int l,int *i)
{
	if (root == NULL)
	{
		return;
	}
	else if (l == 1)
	{
		a[(*i)++] = root->data;
	}
	else if (l > 1){
		getarr(root->right, a, l - 1,i);
		getarr(root->left, a, l - 1,i);
	}
}
int height(struct node * root){
	if (root != NULL)
	{
		int lh = height(root->left);
		int rh = height(root->right);
		if (lh > rh)
		{
			return (lh + 1);
		}
		else return (rh + 1);
	}
	else return 0;
}
int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		int *a = (int *)malloc(sizeof(int) * 100);
		//a[0] = root->data;
		int i = 0;
		int h = height(root);
		int l = 0;
		for (l = 1; l <= h; l++)
		{
			getarr(root, a, l, &i);
		}
		return a;
	}
	
}
