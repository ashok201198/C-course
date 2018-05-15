/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
}*head,*n;

struct node * numberToLinkedList(int N) 
{
	head = NULL;
	if (N <= 0)
	{
		N = -N;
	}
	int m = 0;
	struct node *n = (struct node *)malloc(sizeof(struct node));
	m = N % 10;
	n->num = m;
	n->next = NULL;
	head = n;
	m = N / 10;
	while (m != 0)
	{
		int l;
		struct node *n = (struct node *)malloc(sizeof(struct node));
		l = m % 10;
		n->num = l;
		n->next = head;
		head = n;
		m = m / 10;
	}
	return head;
}