/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>

#define SIZE 31
char ** commonWords(char *str1, char *str2) 
{
	char **result = (char **)malloc(sizeof(char)*SIZE);
	char s1words[100][100], s2words[100][100];
	int l1, l2, ls1=0, ls2=0,i,j;
	if (str1 != NULL&&str2 != NULL)
	{
		l1 = strlen(str1);
		l2 = strlen(str2);
		for (i = 0; i < l1; i++)
		{
			if (str1[i] == ' ')
			{
				ls1++;
			}
		}
		for (i = 0; i < l2; i++)
		{
			if (str2[i] == ' ')
			{
				ls2++;
			}
		}
		if (ls1 == l1 || ls2 == l2)
		{
			return NULL;
		}
		else
		{
			int m = 0, n = 0;
			for (i = 0; i < l1; i++)
			{
				if (str1[i] != ' ')
				{
					s1words[m][n] = str1[i];
					n++;
				}
				else
				{
					s1words[m][n] = '\0';
					m++;
					n = 0;
				}
			}
			s1words[m][n] = '\0';
			m = 0; n = 0;
			for (i = 0; i < l2; i++)
			{
				if (str2[i] != ' ')
				{
					s2words[m][n] = str2[i];
					n++;
				}
				else
				{
					s2words[m][n] = '\0';
					m++;
					n = 0;
				}
			}
			s2words[m][n] = '\0';
			m = 0, n = 0;
			int k = 0;
			for (i = 0; i <=ls1; i++)
			{
				for (j = 0; j <=ls2; j++)
				{
					if (strcmp(s1words[i],s2words[j]) == 0)
					{
						result[k] = s1words[i];
						k++;
					}
				}
			}
			if (k == 0)
			{
				return NULL;
			}
			else
			{
				return result;
			}
		}
	}
	return NULL;
}
