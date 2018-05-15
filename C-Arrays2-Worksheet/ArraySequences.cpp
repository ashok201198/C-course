/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void ap(int *a, int start, int len,int *temp);
void gp(int *a, int start, int len,int *temp);
int * find_sequences(int *arr, int len)
{
	if (arr == NULL || len <= 0)
	{
		return NULL;
	}
	int k = 0;
	int * ap1 = (int *)malloc(sizeof(int) * 2);
	int * ap2 = (int *)malloc(sizeof(int) * 2);
	int * gp1 = (int *)malloc(sizeof(int) * 2);
	int * result = (int *)malloc(sizeof(int) * 6);
	 ap(arr, 0, len,ap1);
	result[0] = ap1[0];
	result[1] = ap1[1];
	ap(arr, result[1], len,ap2);
	result[2] = ap2[0];
	result[3] = ap2[1];
	gp(arr, 0, len,gp1);
	result[4] = gp1[0];
	result[5] = gp1[1];
	return result;
}
void ap(int *a, int start, int len,int *temp)
{
	int r,flag = -1, i = start, l = len;
	while (i<=l - 2)
	{
		r = a[i + 1] - a[i];
		if (a[i + 2] - a[i + 1] == r)
		{
			if(flag==-1)
			{
				temp[0] = i; 
				flag = 0;
			}
			i++;
		}
		else if (a[i + 2] - a[i + 1] != r && flag == 0)
		{
			temp[1] = i+1;
			break;
		}
		else 
		{
			i++; 
		}
		
	}
}
void gp(int *a, int start, int len,int *temp)
{
	int flag = -1, i = start, l = len;
	float r,x;
	while (i<=l - 2)
	{
		r = float(a[i + 1]) /float(a[i]);
		x = float(a[i + 2]) / float(a[i + 1]);
		if (x == r)
		{
			if (flag == -1)
			{
				temp[0] = i;
				flag = 0;
			}
			i++;
		}
		else if (x != r && flag == 0)
		{
			temp[1] = i + 1;
			break;
		}
		else
		{
			i++;
		}

	}
}