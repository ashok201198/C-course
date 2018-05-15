/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
}*temp1,*temp2,*prev1,*prev2,*result,*heada,*headb;
struct node *recur(struct node *res, struct node *t1, struct node *t2);
int merge_circularlists(struct node **head1, struct node **head2)
{
	int l = 0;
	if (*head1 == NULL&&*head2 == NULL)
	{
		return -1;
	}
	temp1 = *head1;
	temp2 = *head2;
	heada = *head1;
	headb = *head2;
	while (temp1->next != heada)
	{
		temp1 = temp1->next;
	}
	temp1->next = NULL;
	while (temp2->next != headb)
	{
		temp2 = temp2->next;
	}
	temp2->next = NULL;
	temp1 = *head1;
	temp2 = *head2;
	*head1= recur(result,temp1, temp2);
	temp1 = *head1;
	while (temp1 != NULL)
	{
		l++;
		prev1 = temp1;
		temp1 = temp1->next;
	}
	prev1->next = *head1;
	return l;
}
struct node *recur(struct node *res, struct node *t1, struct node *t2)
{
	if (t1 == NULL && t2 == NULL)
	{
		return NULL;
	}
	else if (t2 != NULL&&t1 == NULL)
	{
		return t2;
	}
	else if (t1 != NULL&&t2 == NULL)
	{
		return t1;
	}
	if (t1->data < t2->data)
	{
		res = t1;
		res->next = recur(res, t1->next, t2);
	}
	else
	{
		res = t2;
		res->next = recur(res, t1, t2->next);
	}
	return res;
}