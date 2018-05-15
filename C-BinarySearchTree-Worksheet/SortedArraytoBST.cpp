/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};

void insert(struct node * root, int * arr, int i, int j){
	if (root != NULL)
	{
		if (i <=j)
		{
			int mid = (i + j) / 2;
			struct node *n = (struct node *)malloc(sizeof(struct node));
			n->data = arr[mid];
			n->left = NULL;
			n->right = NULL; 
			if (root->data >n->data)
			{
				root->left=n;
				insert(n, arr, i, mid - 1);
				insert(n, arr, mid + 1, j);
			}
			else
			{
				root->right=n;
				insert(n, arr, i, mid - 1);
				insert(n, arr, mid + 1, j);
			}
			
		}
	}
	else
	{
		return;
	}
}
struct node * convert_array_to_bst(int *arr, int len){
	if (arr == NULL || len <= 0)
	{
		return NULL;
	}
	else 
	{
		int i = 0, j = len-1;
		int m = (i + j) / 2;
		struct node * root=(struct node *)malloc(sizeof(struct node ));
		root->data = arr[m];
		root->left = NULL;
		root->right = NULL;
		insert(root, arr, 0,m-1);
		insert(root, arr,m+1, len - 1);
		return root;
	}
}

