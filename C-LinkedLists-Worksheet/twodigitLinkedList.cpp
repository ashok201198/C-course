/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
};

int convert_sll_2digit_to_int(struct twoDigitNode *head)
{
	int num = 0;
	struct twoDigitNode *temp = head;
	while (temp != NULL)
	{
		num = (num * 100) + (temp->digit1) * 10 + (temp->digit2);
		temp = temp->next;
	}
	return num;
}
