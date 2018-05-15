/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct transaction
{
	int amount;
	char date[11];
	char description[20];
};
int validcheck(struct transaction *Arr, int len, char *date);
int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int k, i = 0, j = -1, l = 0;
	k = validcheck(Arr, len, date);
	if (k == 0)
	{
		return 0;
	}
	else
	{
		for (i = 0; i < len; i++)
		{
			l = strcmp(Arr[i].date, date);
			if (l == 0)
			{
				j = i;
			}
		}
		if (j == -1)
			return 0;
		else
		{
			return len - j - 1;
		}

	}
}

	int validcheck(struct transaction *Arr, int len, char *date)
	{
		if (len <= 0 || Arr == NULL)
			return 0;
		if (date[2] != '-' && date[5] != '-')
			return 0;
		int day, mon, yr;
		day = (date[0] - '\0') * 10 + (date[1] - '\0');
		mon = (date[3] - '\0') * 10 + (date[4] - '\0');
		yr = (date[6] - '\0') * 1000 + (date[7] - '\0') * 100 + (date[8] - '\0') * 10 + (date[9] - '\0');
		if (day < 0 && day>31)
			return 0;
		if (mon < 0 && mon>12)
			return 0;
		return 1;
	}
	