/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/
#include<math.h>
#define MAX 1000000000
int nthFibonacci(int n)
{
	int a = 0, b = 1,c,i;
	c = a + b;
	if (n > 0)
	{
		for (i = 2; i < n-1; i++)
		{
			a = b; b = c;
			c = a + b;
		}
		return c;
	}
	else return -1;
}

int nthPrime(int n)
{
	int i, j, temp, count = 0;
	if (n > 0)
	{
		for (i = 2; i <= MAX; i++)
		{
			temp = 0;
			for (j = 2; j <= i/2; j++)
			{
				if (i%j == 0)
				{
					temp = 1;
					break;
				}
			}
			if (temp == 0)
			{
				count++;
			}
			if (count == n)
			{
				return i;
				break;
			}
		}

	}
	else return -1;
}