/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <stdlib.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i,j,t;
	if (Arr!=NULL&&len>0)
	{
		Arr == realloc(Arr, 10);
		Arr[len] = num;
		len++;
		for (i = 0; i < len; i++)
		{
			for (j = i+1; j < len; j++)
			{
				if (Arr[i]>Arr[j])
				{
					t = Arr[i];
					Arr[i] = Arr[j];
					Arr[j] = t;
				}
			}
		}
		return Arr;
	}
	else
	{
		return NULL;
	}
}