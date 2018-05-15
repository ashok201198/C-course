/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"
#include<stdlib.h>
int check(int *a, int i, int j, int n);
int checkRight(int *a, int i, int j, int n);
int checkLeft(int *a, int i, int j, int n);
int checkuP(int *a, int i, int j, int n);
int checkRight(int *a, int i, int j, int n){
	if (i < n&&j < n&&i >= 0 && j >= 0)
	{
		if (a[i*n + j] == 0)
		{
			return checkRight(a, i -1, j + 1, n);
		}
		else return 0;
	}
	else return 1;
}
int checkLeft(int *a, int i, int j, int n){
	if (i < n&&j < n&&i >= 0 && j >= 0)
	{
		if (a[i*n + j] == 0)
		{
			return checkLeft(a, i - 1, j-1, n);
		}
		else return 0;
	}
	else return 1;
}
int checkUp(int *a, int i, int j,int n)
{
	if (i < n&&j < n&&i>=0&&j>=0)
	{
		if (a[i*n + j] == 0)
		{
			return checkUp(a, i - 1, j, n);
		}
		else return 0;
	}
	else return 1;
}
int check(int *a, int i, int j,int n)
{
	int l = checkUp(a, i, j,n);
	if (l == 0) return 0;
	int m = checkLeft(a, i, j,n);
	if (m == 0) return 0;
	int o = checkRight(a, i, j,n);
	if (o == 0) return 0;
	else return 1;
}
int sniprec(int *a, int n, int i, int j, int * flag){
	if (i >= n&&flag[i-1] == 1)
	{
		return 1;
	}
	else
	{
		if (i < n&&j < n&&i >= 0 && j >= 0)
		{
			int b;
			if (flag[i] == 0)
			{
				for (j = 0; j < n; j++)
				{
					if (check(a, i, j, n) == 1)
					{
						flag[i] = 1;
						a[i*n + j] = 1;
						b = sniprec(a, n, i + 1, 0, flag);
						if (b == 1)
						{
							return b;
						}
						if (b == 0)
						{
							flag[i] = 0;
							a[i*n + j] = 0;
						}
					}
				}
				//return 0;
				return 0;
			}
		}
		else return 0;
	}
}
int solve_nsnipers(int *battlefield, int n)
{ if (battlefield==NULL||n<=3)
	return 0;
else
{
	int * flag = (int *)calloc(sizeof(int),n);
	return sniprec(battlefield, n, 0, 0, flag);
}
}
