/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void ino(struct node *root, int *arr, int *i)
{
	if (root == NULL||arr==NULL){ return; }
	else if (root != NULL)
	{
		ino(root->left, arr, i);
		arr[*i] = root->data;
		(*i)++;
		ino(root->right, arr, i);
	}
}
void pre(struct node *root, int *arr, int *i)
{
	if (root == NULL || arr == NULL){ return; }
	else if(root != NULL)
	{
		arr[*i] = root->data;
		(*i)++;
		pre(root->left, arr, i);
		pre(root->right, arr, i);
	}
}
void post(struct node *root, int *arr, int *i)
{
	if (root == NULL || arr == NULL){ return; }
	else if (root != NULL)
	{
		post(root->left, arr, i);
		post(root->right, arr, i);
		arr[*i] = root->data;
		(*i)++;
	}
}
void inorder(struct node *root, int *arr){
	/*static int i = 0;
	if (root != NULL)
	{
	inorder(root->left, arr);
	arr[i] = root->data;
	i++;
	inorder(root->right, arr);
	}*/
	if (root != NULL&&arr != NULL){
	int  i = 0;
	ino(root, arr, &i);
}
}
void preorder(struct node *root, int *arr){
	/*static int j = 0;
	if (root!=NULL)
	{
		arr[j] = root->data;
		j++;
		preorder(root->left, arr);
		preorder(root->right, arr);
	}*/
	if (root != NULL&&arr != NULL){
		int i = 0;
		pre(root, arr, &i);
	}
}
void postorder(struct node *root, int *arr){
	/*static int k = 0;
	if (root!=NULL)
	{
		postorder(root->left, arr);
		postorder(root->right, arr);
		arr[k] = root->data;
		k++;
	}*/
	if (root != NULL&&arr != NULL){
		int i = 0;
		post(root, arr,& i);
	}
}

