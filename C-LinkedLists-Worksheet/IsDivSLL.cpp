/*
Problem Code : ISDIVSLL

You are Given an SLL where each Node has a character (which is picked from digits or '-'/'+') and a Key integer .
Example SLL : '1' -> '2' -> '3' -> '4'

You need to return 1 if the sum of numbers formed by (the SLL and reverse SLL) is divisible by key ,Return 0 otherwise . Return -1 for invalid cases  .

Sample Input :
SLL: '+'->'1'->'3'->'6'; (which is 136) and Key is 59 .

Sample Output :
1

If Key is 67 in the above example ,You should return 0 .

Explanation :
SLL is 136 , Reverse SLL is 631 . Sum is 631+136 = > 767 . 767 is divisible by 59 , So you should return 1 .

Constraints :

->Characters Range will be in from the following string "+-0123456789" .
->Length of SLL will be less than 10Nodes .
->0<=Key<=10000000
->First char need not defenetly be a sign , if its a digit ,it is considered as a positive number .

Note : Reverse of a negetive SLL is negetive only .And -963 can be divided by 3 .
*/

#include <stddef.h>
#include <malloc.h>
#include <stdio.h>

struct charNode{
	char letter;
	struct charNode *next;
};

int isDivisibleSLL(struct charNode * head, int key)
{
	if (head == NULL || key == 0)
	{
		return -1;
	}
	struct charNode *temp = head;
	struct charNode *pres = head;
	char c;
	int num=0;
	if (temp->letter == '+' || temp->letter == '-')
	{
		c = temp->letter;
		pres = temp->next;
	}
	while (pres != NULL)
	{
		int l = ((pres->letter) - '0');
		num = num * 10 + l;
		pres = pres->next;
	}
	int tem = num;
	int rev = 0;
	while (tem != 0)
	{
		rev = rev * 10 + (tem % 10);
		tem = tem / 10;
	}
	if (c == '-')
	{
		num = num*-1;
		rev = rev*-1;
	}
	int sum = num + rev;
	if (sum%key == 0)
	{
		return 1;
	}
	else return 0;
}

