/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node *rec(struct node *res, struct node *t1, struct node *t2);
struct node * merge2LinkedLists(struct node *head1, struct node *head2)
{
	/*if (head1 == NULL && head2 == NULL)
	{
		return NULL;
	}
	else if (head2 != NULL&&head1 == NULL)
	{
		return head2;
	}
	else if (head1 != NULL&&head2 == NULL)
	{
		return head1;
	}
	struct node *temp1=head1, *temp2=head2,*temp3,*prev=head1;
	while (temp1 != NULL && temp2 != NULL)
	{
		if (temp1->num <= temp2->num)
		{
			temp3 = temp2->next;
			temp2->next = temp1->next;
			temp1->next = temp2;
			temp2 = temp3;
			temp1 = temp1->next;
		}
		else
		{
			temp3 = temp2->next;
			temp1 = temp2->next;
			prev->next = temp2;
			temp3 = temp2;
			prev = prev->next;
			temp1 = temp1->next;
		}
	}
	return head1;*/
	struct node * result = NULL, *temp1 = head1,*temp2=head2,*head;
	head=rec(result, temp1, temp2);
	return head;
}
struct node *rec(struct node *res, struct node *t1, struct node *t2)
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
	if (t1->num < t2->num)
	{
		res = t1;
		res->next=rec(res, t1->next, t2);
	}
	else
	{
		res = t2;
		res->next=rec(res, t1, t2->next);
	}
	return res;
}