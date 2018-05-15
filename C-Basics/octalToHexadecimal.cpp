/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	long int n=0,t=0,o=0;
	int i = 0;
	if (num >0)
	{
		while (num != 0)
		{
			t = pow(8.0, i);
			n = n+(num % 10)*t;
			num /= 10;
			i++;
		}
		i = 0;
		while (n != 0)
		{
			o = o + (n % 16) * pow(10.0,i);
			n = n / 16;
			i++;
		}
		return o;
	}
	else
	{
		return 0;
	}
	
}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}