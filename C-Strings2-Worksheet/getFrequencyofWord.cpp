/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>
#include<string.h>
void substring(char *str,char*sub,int i, int w);
int comp(char *str, char *sub);
int count_word_in_str_way_1(char *str, char *word)
{
	int w = 0, s = 0,i,k=0;
	if (str == NULL || word == NULL)
	{
		return 0;
	}
	while (word[++w]){}
	while (str[++s]){}
	char *sub = (char *)malloc(sizeof(char)*w);
	for (i = 0; i < s-w+1; i++)
	{
		substring(str,sub,i,w);
		if (comp(sub, word) == 0)
		{
			k++;
		}
	}
	return k;
}
void substring(char *str, char * sub, int i, int w)
{
	int k = 0;
	int j = i + w;
	while (i < j){
		sub[k] = str[i];
		k++; i++;
	}
	sub[k] = '\0';
}
int comp(char *str, char *sub)
{
	int i = 0;
	while ((str[i] != '\0') || (sub[i] != '\0'))
	{
		if (str[i] > sub[i])
			return 1;
		if (str[i] < sub[i])
			return -1;
		i++;
	}
	return 0;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

