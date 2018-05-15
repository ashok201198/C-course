
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include<stdlib.h>
int* nPrime(int N)
{
	int i = 0, c = 0, j = 0, k = 0;
	int *a = (int *) malloc (10 * sizeof(int));
	int *b;
	if (N > 1)
	{
		for (j = 2; j <= N; j++)
		{
			c = 0;
			for (i = 2; i <= j / 2; i++)
			{
				if (j%i == 0)
				{
					c++;
				}
			}
			if (c == 0)
			{
				a[k] = j;
				k++;
			}
		}
		b = (int *)malloc(k * sizeof(int));
		for (i = 0; i < k; i++)
		{
			b[i] = a[i];
		}
		return b;
	}
	else return NULL;
}