/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: 
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include<malloc.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
}*result=NULL;

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int k = 0, i = 0,l,m=0,j,n;
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
	{
		return NULL;
	}
	if (BLen > ALen)
	{
		k = BLen;
		n = ALen;
	}
	else
	{
		n = BLen;
		k = ALen;
	}
	result = (struct transaction *)malloc(sizeof(struct transaction)*n);
	for (i = 0; i < n; i++)
		{
			for (j = 0; j < k; j++)
			{
				l = strcmp(A[j].date, B[i].date);
				if (l == 0)
				{
					result[m] = A[j];
					m++;
					break;
				}
			}
		}
	if (m == 0)
	{
		return NULL;
	}
	return result;
	}

