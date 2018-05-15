/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spirec(int i, int j, int r, int c, int sr, int sc, int ** ip, int *a, int len, int k, int f)
{
if (k >= len)
	{
		return;
	}
	else
	{
		if (j < c && i == sr&&f == 1)
		{
			a[k] = ip[i][j];
			//printf("element =%d at %d\n", a[k], k);
			k++;
			spirec(i, j + 1, r, c, sr, sc, ip, a, len, k, f);
		}
		else if (j == c&&i < r)
		{
			f = 0;
			if (i == sr)
			{
				i = i + 1;
			}
			a[k] = ip[i][j - 1]; 
			//printf("element =%d at %d\n", a[k], k);
			k++;
			spirec(i + 1, j, r, c, sr, sc, ip, a, len, k, f);
		}
		else if (j >sc&&i == r)
		{
			if (j == c)
			{
				j = j - 2;
			}
			a[k] = ip[i - 1][j];
			// printf("element =%d at %d\n", a[k], k);
			k++;
			spirec(i, j - 1, r, c, sr, sc, ip, a, len, k, f);
		}
		else if (j == sc&&i <= r&&i>sr)
		{
			if (i == r)
			{
				i--;
			}
			a[k] = ip[i][j]; 
			//printf("element =%d at %d\n", a[k], k);
			k++;
			spirec(i - 1, j, r, c, sr, sc, ip, a, len, k, f);
		}
		else if (j == sc&&i == sr)
		{
			sc++;
			f = 1;
			sr++;
			r--;
			c--;
			i = sr;
			j = sc;
			spirec(i, j, r, c, sr, sc, ip, a, len, k, f);
		}
	}
}
int *spiral(int rows, int columns, int **input_array)
{
	if (rows <=0 || columns <=0 || input_array == NULL)
	{
		return NULL;
	}
	else {
		int l = rows*columns;
		int *a = (int *)malloc(sizeof(int)*l);
		spirec(0, 0, rows, columns, 0, 0, input_array, a,l, 0, 1);
		return a;
	}
}
