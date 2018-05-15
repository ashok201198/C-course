/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>
void temp_to_result(int *temp, int templen, int *result);
void pillars_max_jumps_recursion_wrapper(int **blocks, int x1, int y1, int m, int n, int *temp, int templen, int *result, int *resultlen);
void pillars_max_jumps_recursion(int **blocks, int x1, int y1, int x2, int y2, int m, int n, int *temp, int templen, int *result, int *resultlen);


void temp_to_result(int *temp, int templen, int *result)
{
	int i;

	for (i = 0; i < templen; i++)
	{
		result[i] = temp[i];
	}
}

void pillars_max_jumps_recursion_wrapper(int **blocks, int x1, int y1, int m, int n, int *temp, int templen, int *result, int *resultlen)
{
	int x2, y2;

	x2 = x1; y2 = y1 - 1;
	templen = 0;

	if (y2 >= 0 && (blocks[x2][y2] > blocks[x1][y1]) && (blocks[x1][y1]>0))
	{
		temp[templen++] = blocks[x1][y1];
		pillars_max_jumps_recursion(blocks, x1, y1, x2, y2, m, n, temp, templen, result, resultlen);
	}


	x2 = x1 - 1; y2 = y1;
	templen = 0;
	if (x2 >= 0 && (blocks[x2][y2] > blocks[x1][y1]) && (blocks[x1][y1]>0))
	{
		temp[templen++] = blocks[x1][y1];
		pillars_max_jumps_recursion(blocks, x1, y1, x2, y2, m, n, temp, templen, result, resultlen);
	}

	x2 = x1; y2 = y1 + 1;
	templen = 0;
	if (y2 < n && (blocks[x2][y2] > blocks[x1][y1]) && (blocks[x1][y1]>0))
	{
		temp[templen++] = blocks[x1][y1];
		pillars_max_jumps_recursion(blocks, x1, y1, x2, y2, m, n, temp, templen, result, resultlen);
	}

	x2 = x1 + 1; y2 = y1;
	templen = 0;
	if (x2 < m && (blocks[x2][y2] > blocks[x1][y1]) && (blocks[x1][y1]>0))
	{
		temp[templen++] = blocks[x1][y1];
		pillars_max_jumps_recursion(blocks, x1, y1, x2, y2, m, n, temp, templen, result, resultlen);
	}
}

void pillars_max_jumps_recursion(int **blocks, int x1, int y1, int x2, int y2, int m, int n, int *temp, int templen, int *result, int *resultlen)
{
	if (x2 >= 0 && x2<m&&y2 >= 0 && y2<n && (blocks[x2][y2] > blocks[x1][y1]) && (blocks[x1][y1]>0))
	{
		temp[templen++] = blocks[x2][y2];
		pillars_max_jumps_recursion(blocks, x2, y2, x2, y2 - 1, m, n, temp, templen, result, resultlen);
		pillars_max_jumps_recursion(blocks, x2, y2, x2 - 1, y2, m, n, temp, templen, result, resultlen);
		pillars_max_jumps_recursion(blocks, x2, y2, x2, y2 + 1, m, n, temp, templen, result, resultlen);
		pillars_max_jumps_recursion(blocks, x2, y2, x2 + 1, y2, m, n, temp, templen, result, resultlen);
		if (templen > *resultlen)
		{
			*resultlen = templen;
			temp_to_result(temp, templen, result);
			templen = 0;
		}
	}
}

int * pillars_max_jumps(int *blocks, int m, int n, int *jumps_count)
{
	if (blocks == NULL || n <= 0 || m <= 0)
		return NULL;
	int **blocks_2d = (int **)malloc(sizeof(int *)*m);
	int i, j, k;
	for (i = 0; i < m; i++)
	{
		blocks_2d[i] = (int *)malloc(sizeof(int)*n);
	}

	k = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			blocks_2d[i][j] = blocks[k];
			k++;
		}
	}

	int all_are_zeroes = 1;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (blocks_2d[i][j] == 0)
			{

			}
			else
			{
				all_are_zeroes = 0;
				break;
			}
		}
	}

	if (all_are_zeroes == 1)
		return NULL;


	int *result = (int *)malloc(sizeof(int)*(m*n));
	int *temp = (int *)malloc(sizeof(int)*(m*n));

	int templen, resultlen;

	templen = 0;
	resultlen = 0;

	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			templen = 0;
			pillars_max_jumps_recursion_wrapper(blocks_2d, i, j, m, n, temp, templen, result, &resultlen);
		}
	}

	if (resultlen == 0)
	{
		*jumps_count = 0;
		result[0] = 1;
		return result;
	}
	else
	{
		*jumps_count = resultlen - 1;
		return result;
	}
}