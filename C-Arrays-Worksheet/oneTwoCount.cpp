/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2] 
	output: [3,4]
	where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array 

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/

#include <stdio.h>
#include<stdlib.h>
int* oneTwoCount(int* i, int l)
{
	int j, k=0,m=0;
	int *a=(int *)malloc(sizeof(int)*2);
	a[0] = 0;
	a[1] = 0;
	if (i[0] != '/0'&&l>0)
	{
		for (j = 0; j < l; j++)
		{
			if (i[j] == 1)
			{
				k++;
			}
			else if (i[j] == 2)
			{
				m++;
			}
		}
		a[0] = k;
		a[1] = m;
		return a;
	}
	else
	{
		return NULL;
	}
}