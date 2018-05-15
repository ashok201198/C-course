/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int count(struct node *date,int *a);
int between_days(struct node *date1head, struct node *date2head)
{
	if (date1head == NULL || date2head == NULL)
	{
		return -1;
	}
	else
	{
		int a[13]={ 0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int m = count(date1head,a);
		int n = count(date2head,a);
		int k = m - n;
		if (k == 0||k==1||k==-1)
		{
			return 0;
		}
		else if (k < -1)
		{
			k = -k;
		}
		return k-1;
	}
}
int count(struct node *date,int *a)
{
	struct node*temp = date;
	int i = 2;
	int d=0, m=0, y=0;
	while (i--)
	{
		d = d * 10 + temp->data;
		temp = temp->next;
	}
	i = 2;
	while (i--)
	{
		m = m * 10 + temp->data;
		temp = temp->next;
	}
	i = 4;
	while (i--)
	{
		y = y * 10 + temp->data;
		temp = temp->next;
	}
	int mo=0;
	for (int k = 0; k < m; k++)
	{
		mo += a[k];
	}
	int l;
	if (m > 2)
	{
	l = (y / 4) + (y / 400) - (y / 100);
	}
	else l = ((y-1) / 4) + ((y-1) / 400) - ((y-1) / 100);
	return ((365 * y) + l + d + mo-1);
}