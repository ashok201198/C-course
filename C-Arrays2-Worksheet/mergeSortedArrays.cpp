/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int compare(char *str1, char *str2);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	int i = 0,j=0,k=0,l;
	struct transaction * result = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
	{
		return NULL;
	}
	while (i != (ALen + BLen))
	{
		if (j < ALen&&k < BLen)
		{
			l=compare(A[j].date, B[k].date);
			if (l < 0)
			{
				result[i] = A[j];
				j++;
				i++;
			}
			else if (l == 0)
			{
				result[i] = A[j];
				i++;
				j++;
				result[i] = B[k];
				k++;
				i++;
			}
			else if (l > 0)
			{
				result[i] = B[k];
				i++;
				k++;
			}
		}
		else if (j == ALen&&k < BLen)
		{
			for (int f = k; f < BLen; f++)
			{
				result[i] = B[f];
				i++;
			}
		}
		else if (k == BLen&&j < ALen)
		{
			for (int f = j; f < ALen; f++)
			{
				result[i] = A [f];
				i++;
			}
		}
		
	}
	return result;
}
int compare(char *str1, char *str2)
{
	int l=0;
	int s1y, s2y, s1m, s2m, s1d, s2d;
	s1y = (str1[6]-'\0')* 1000 + (str1[7]-'\0' )* 100 + (str1[8]-'\0' )* 10 + (str1[9]-'\0');
	s2y = (str2[6] - '\0') * 1000 + (str2[7] - '\0') * 100 + (str2[8] - '\0') * 10 + (str2[9] - '\0');
	s1m = (str1[3] - '\0') * 10 + (str1[4] - '\0');
	s2m = (str2[3] - '\0') * 10 + (str2[4] - '\0');
	s1d = (str1[0] - '\0') * 10 + (str1[1] - '\0');
	s2d = (str2[0] - '\0') * 10 + (str2[1] - '\0');
	if (s1y > s2y)
	{
		return 1;
	}
	else if (s1y < s2y)
	{
		return -1;
	}
	else 
	{
		if (s1m>s2m)
		{
			return 1;
		}
		else if (s1m < s2m)
		{
			return -1;
		}
		else
		{
			if (s1d>s2d)
			{
				return 1;
			}
			else if (s1d < s2d)
			{
				return -1;
			}
			else return 0;
		}
	}
	return l;
}