/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) 
{
	if (head == NULL)
	{
		return -1;
	}
	else
	{
		int len = 0,i,j;
		struct node *temp = head;
		while (temp != NULL)
		{
			len++;
			temp = temp->next;
		}
		temp = head;
		if (len == 1)
		{
			return temp->num;
		}
		if (len % 2 == 0)
		{
			temp = head;
			i = len / 2-1;
			j = len / 2;
			while (i--)
			{
				temp = temp->next;
			}
			int x = temp->num;
			temp = head;
			while (j--)
			{
				temp = temp->next;
			}
			int y = temp->num;
			return ((x + y) / 2);
		}
		else
		{
			i = len / 2;
			while (i--)
			{
				temp = temp->next;
			}
			return temp->num;
		}
	}
}
