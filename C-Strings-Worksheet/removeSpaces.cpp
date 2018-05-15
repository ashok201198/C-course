/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char removeSpaces(char *str) {
	int i=0,j=0,l=0;
	if (str == NULL||str=="")
	return '\0';
	while (str[l]!='\0'){
	
		l++;
	}
	for (i = 0; i < l; ++i)
	{
		if (str[i] != 32)
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
}