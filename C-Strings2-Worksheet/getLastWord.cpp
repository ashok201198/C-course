/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include<string.h>
#include <stdlib.h>
char * get_last_word(char * str)
{
	int i,l=0,k=0;
	while (str[++l]){}
	if (l==0||str==NULL)
	{
		return NULL;
	}
	char *res = (char *)malloc(sizeof(char) * l);
	i = l;
	while (str[i] != ' ')
	{
		i--;
	}
	for (int j = i; str[j] != ' '; j--)
	{
		res[k] = str[j];
		k++;
	}
	res[k] = '\0';
	_strrev(res);
	return res;
}
