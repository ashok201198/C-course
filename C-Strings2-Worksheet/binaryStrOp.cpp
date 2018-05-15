/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>


char *performOperation(char *str1, char *str2, char *operation){
	int l = -1, m = -1, c = 0, size = 0,i;
	char *output;
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	while (str1[++l]){}
	while (str2[++m]){}
	if (l == 0)
	{
		if (m == 0)
		{
			return NULL;
		}
		for (int i = 0; i < m; i++)
		{
			str1[i] = '0';
		}
		l = m;
	}
	if (m == 0)
	{
		for (int i = 0; i < l; i++)
		{
			str2[i] = '0';
		}
		m = l;
	}
	if (l == m)
	{
		size = l;
	}
	if (l < m)
	{
		for (int i = l; i >= 0; i--)
		{
			str1[i + m-l] = str1[i];
		}
		for (int i = 0; i < m-l; i++)
		{
			str1[i] = '0';
		}
		c = 1;
		size = m;
	}
	if (m < l)
	{
		for (int i = m; i >= 0; i--)
		{
			str2[i + l - m] = str2[i];
		}
		for (int i = 0; i < l-m; i++)
		{
			str2[i] = '0';
		}
		size = l;
	}
	output = (char *)malloc(sizeof(char)*(size + 1));
	switch (operation[0])
	{
	case 'A':
		for (i = 0; i < size; i++)
		{
			if (str1[i] == '1'&&str2[i] == '1')
			{
				output[i] = '1';
			}
			else output[i] = '0';
		}
		output[i] = '\0';
		break;
	case 'O':for (i = 0; i < size; i++)
	{
		if (str1[i] == '1'||str2[i] == '1')
		{
			output[i] = '1';
		}
		else output[i] = '0';
	}
			 output[i] = '\0';
		break;
	case 'N':for (i = 0; i < size; i++)
	{
		if (str1[i] == '0'&&str2[i] == '0')
		{
			output[i] = '1';
		}
		else output[i] = '0';
	}
			 output[i] = '\0';
		break;
	case 'X':for (i = 0; i < size; i++)
	{
		if ((str1[i] == '1'&&str2[i] == '1') || (str1[i] == '0'&&str2[i] == '0'))
		{
			output[i] = '0';
		}
		else output[i] = '1';
	}
			 output[i] = '\0';
		break;
	default:break;
	}
	return output;
}








