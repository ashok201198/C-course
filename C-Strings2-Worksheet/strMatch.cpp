/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
int createString(char *src,int i ,char *dest,int j);
int cmp(char *str1, char *str2);
int isSTRMatched(char *str1, char *str2)
{
	int j,k,l=0,m=0;
	if (str1 == NULL||str2 == NULL)
	{
		return -1;
	}
	while (str1[l] != '\0'){ l++; }
	while (str2[m] != '\0'){ m++; }
	if (l == 0)
	{
		if (m == 0)
		{
			return 1;
		}
		else return 0;
	}
	char *stra = (char *)malloc(sizeof(char) * 1000);
	char *strb = (char *)malloc(sizeof(char) * 1000);
	j=createString(str1,0,stra,0);
	j=createString(str2,0,strb,0);
	k = cmp(stra, strb);
	return k;
}
int createString(char *src,int i,char *dest,int j)
{
	int k=0;
	if (src[i] == '\0')
	{
		dest[j] = '\0';
		return 0;
	}
	else if (src[i]!='\0')
	{
		if (src[i] >= 97 && src[i] <= 122)
		{
			dest[j] = src[i];
			j++;
		}
		else if (src[i] >= 48 && src[i] <= 57)
		{
			int l = i;
			while (!(src[l] >= 97 && src[l] <= 122)&&src[l]!='\0')
			{
				k = k * 10 + (src[l] - '0');
				l++;
			}
			for (int m = 0; m < k; m++)
			{
				dest[j] = '.';
				j++;
			}
		}
		i++;
	}
	k=createString(src, i, dest, j);
}
int cmp(char *str1, char *str2)
{
	int i = 0,l=-1,m=-1;
	while (str1[++l]){}
	while (str2[++m]){}
	if (l != m)
	{
		return 0;
	}
	else
	{
		while (i!=l)
		{
			if (str1[i] == str2[i])
			{
			}
			else if (str1[i] == '.' || str2[i] == '.')
			{
			}
			else { return 0; }
			i++;
		}
	}
	return 1;
}