/*
Given a Sorted Doubly Linked List and a Binary Search Tree , 
Check if they are identical or not .
The DLL will have nodes of type node_dll

Note :
	A DLL can be represented as a BST in many forms ,
	And if a dll and any one of the forms is given as input you
	need to return 1 otherwise 0.

	->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

	Example 0:
	
	DLL:1->5->8

	BST(All 3 return 1):

	  5         8      1
	 / \       /        \
    1   8     5          5
               \
                8

		Returns 1


Example 1:
	
		DLL : 1->5
		
		BST :
			5
			 \
			  10
		
		Returns 0

Example 2:

	DLL:1->3->5-9->11
	
		BST:
		
		 5
		/ \
	   1   11
		\  /
		3 9

	Returns 1


Example 3:
	
	DLL: 1->5->7->10->12->15->20
		
		BST:
		
		  10
		 /   \
	    5    15
	   / \   / \
	  1  7  12 20
Returns 1

Note 2 :
	Unequal Length BST and DLL should return 0;
	Return -1 for NULL inputs

*/

#include<stdio.h>
#include<stdlib.h>

struct node_dll {
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

struct node_bst {
	int data;
	struct node_bst *left;
	struct node_bst *right;
};
void find(struct node_bst *root, struct node_dll **head, int *i)
{
	if (root != NULL)
	{
		find(root->left, head, i);
		if (root->data == (*head)->data)
		{
			(*i)++;
			(*head) = (*head)->next;
		}
		else 
		{
			return;
		}
		find(root->right, head, i);
		
	}
}
void elements(struct node_bst *root, int *i)
{
	if (root != NULL)
	{
		elements(root->left, i);
		(*i)++;
		elements(root->right, i);
	}
}
int length(struct node_dll *head)
{
	int i = 0;
	struct node_dll *temp = head;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}
int is_identical(struct node_dll *head, struct node_bst *root) 
{
	if (head == NULL || root == NULL)
	{
		return -1;
	}
	else
	{
		int l = length(head);
		int i = 0;
		elements(root,&i);
		if (l != i)
		{
			return 0;
		}
		struct node_dll *temp = head;
		int j = 0;
		struct node_bst *temp2 = root;
		find(temp2, &temp, &j);
		if (j == i)
		{
			return 1; 
		}
		else 
		{
			return 0; 
		}
	}
}