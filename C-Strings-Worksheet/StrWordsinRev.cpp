/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void rev(char *input, int i, int j);
void str_words_in_rev(char *input, int len)
{
	int i = 0, j = -1,c=0;
	for (i = 0; i < len; i++)
	{
		if (input[i] == 32)
		{
			c++;
			break;
		}
	}
	if (c != 0)
	{
		c = 0;
		strrev(input);
		for (i = 0; i <= len; i++)
		{
			if (input[i] == ' ' || i == len)
			{
				rev(input, i, j);
				j = i;
			}
		}
	}
}

void rev(char *input, int i, int j)
{
	int k, l;
	char t;
	for (k = j + 1, l = i - 1; k < i; k++, l--)
	{
		if (k >= l)
		{
			break;
		}
		t = input[k];
		input[k] = input[l];
		input[l] = t;
	}

}