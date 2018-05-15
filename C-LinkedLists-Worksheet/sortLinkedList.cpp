/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
}*temp,*prev;

struct node * sortLinkedList(struct node *head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	else 
	{
		temp = head;
		prev = temp->next;
		while (temp != NULL)
		{
			prev = temp->next;
			while (prev != NULL)
			{
				if (temp->num > prev->num)
				{
					int t = temp->num;
					temp->num = prev->num;
					prev->num = t;
				}
				prev = prev->next;
			}
			temp = temp->next;
		}
	}
	return head;
}