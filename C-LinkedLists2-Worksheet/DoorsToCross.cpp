/*

Bharath is genius reverse engineer, invented a world demanding machine and Kept in a secret building with many doors with each door having a passkey.
A Pass key is made up of some digits. Like a passkey can be 1234, 452 etc.
All doors will have passkeys of same digits, (formed from each other). like if number of doors are 3, 1223,2132,2321 can be passkeys for those doors. 
(Where as 3321 cannot as 3 is repeated 2 times where as in above sequence its repeated only 1 time)

Sam is very excited to see his wonderful creation. So, she went to the building. She knows the final passkey of last door but dont know
what is the exact passkey for each before door. As said before there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door. she can cross third door only after crossing 2nd door.

Lets say the final pass key she has is 758.
First door pass key is the largest number that can be formed by given final passkey -> 875
Second door pass key is the next largest number that can be formed -> 857
Third door opens for next largest number ->785
Finally fourth door has 758 as passkey and she can enter the room.

Find which Nth door's room contains the machine or How many doors should Sam cross to see the machine?

The final passkey Sam has will be given in the form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

For the above Passkey ,output will be 4, as Sam needs to cross 4 doors which each door having below passkeys.
explanation: (1) 875 (2) 857 (3) 785 (4) 758

Ex 2 : 
If DLL has 9 <-> 1 <-> 4 <-> 6.
For the above Passkey ,output will be 4, as Sam needs to cross 6 doors which each door having below passkeys.
explanation: (1) 9641 (2) 9614 (3) 9461 (4) 9416 (5) 9164 (6) 9146

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

You can solve this question in multiple ways. 
Can you solve it without converting to any intermediate forms or using extra space etc? These will be the common followup questions
that can be asked in an interview.

Return -1 for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};

int doorstoCross(struct passKeyNode *passKeyHead)
{
	if (passKeyHead == NULL)
		return -1;

	struct passKeyNode *temp, *temp1, *temp2, *leastgreater,*start,*last,*temp1start,*temp1sort,*temp2sort;
	int count = 1, large= 0, swap, l = 0;
	temp = passKeyHead;
	while (temp != NULL)
	{
		l++;
		temp = temp->next;
	}
	if (l== 0)
		return -1;
	
	start = passKeyHead;
	temp = start;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	last = temp;

	while (large==0)
	{
		temp2 = last;
		temp1 = last->prev;
		while (1)
		{
			if (temp1 != NULL)
			{
				if (temp1->num >= temp2->num)
				{
					temp2 = temp1;
					temp1 = temp1->prev;
				}
				else
					break;
			}
			else
			{
				large = 1;
				break;
			}
		}
		if (large == 1)
			break;
		temp1start = temp1;
		if (temp2->next != NULL)
		{
			leastgreater = temp1start->next;
			temp = leastgreater->next;
			while (temp != NULL)
			{
				if (temp->num > temp1->num)
				{
					if (temp->num < leastgreater->num)
					{
						leastgreater = temp;
					}
				}
				temp = temp->next;
			}
			swap = temp1->num;
			temp1->num = leastgreater->num;
			leastgreater->num = swap;
			leastgreater = temp;
		}
		else
		{
			swap = temp1->num;
			temp1->num = temp2->num;
			temp2->num = swap;
		}
		temp1sort = temp2;
		while (temp1sort != NULL)
		{
			temp2sort = temp1sort->next;
			while (temp2sort != NULL)
			{
				if (temp1sort->num > temp2sort->num)
				{
					swap = temp1sort->num;
					temp1sort->num = temp2sort->num;
					temp2sort->num = swap;
				}
				temp2sort = temp2sort->next;
			}
			temp1sort = temp1sort->next;
		}
		count++;
	}
	return count;
}