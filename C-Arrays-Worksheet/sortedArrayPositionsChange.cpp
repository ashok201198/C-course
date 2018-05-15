/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *a, int len)
{
	int i=0, j=len-1, k;
	if (a==NULL||len<0)
		return NULL;
	else {
		while(i < j)
		{
			for (i = 0; i < len; i++)
			{
				if (a[i]>a[i + 1])
				{
					break;
				}
			}
			for (j = len - 1; j >= 0; j--)
			{
				if (a[j] < a[j - 1])
				{
					break;
				}
			}
			if (i < j)
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
}