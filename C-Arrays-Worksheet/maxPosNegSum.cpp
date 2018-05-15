
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int l)
{
	int i, b, s, cp = 0, cn = 0;
	if (l > 0 && input[0] != '/0')
	{
		for (i = 0; i < l; i++)
		{
			if (input[i] >= 0)
			{
				cp++;
				b = input[i];
			}
			else if (input[i] < 0)
			{
				cn++;
				s = input[i];
			}
		}
		if (cp == l || cn == l)
		{
			return 0;
		}
		else
		{
			for (i = 1; i < l; i++)
			{
				if (b < input[i])
				{
					b = input[i];
				}
			}
			for (i = 0; i < l; i++)
			{
				if (input[i] < 0)
				{
					if (s < input[i])
					{
						s = input[i];
					}
				}
			}
			if (s < 0)
				return s + b;
			else return 0;
		}
	}
	else return 0;

}