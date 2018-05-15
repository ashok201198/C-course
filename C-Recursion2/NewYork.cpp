/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2

(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/

#include <stdio.h>
#include <stdlib.h>

void newyork_recur(int n, int m, int x, int y, int k,int *i,int prev)
{
	if ((x == n && y == m)&&(k==0))
	{
		(*i)++;
	}
	else if (x != n||y != m)
	{
		if ((x >= 0 && y >= 0) && (x <= n && y <= m))
		{
			if (k >= 0)
			{
				if (prev == 0)
				{
					newyork_recur(n, m, x + 1, y, k, i, 2);
					newyork_recur(n, m, x, y + 1, k, i, 3);
				}
				else
				{
					if (prev == 1)
					{
						newyork_recur(n, m, x - 1, y, k, i, 1);
					}
					else
					{
						newyork_recur(n, m, x - 1, y, k - 1, i, 1);
					}
					if (prev == 2)
					{
						newyork_recur(n, m, x + 1, y, k, i, 2);
					}
					else
					{
						newyork_recur(n, m, x + 1, y, k - 1, i, 2);
					}
					if (prev == 3)
					{
						newyork_recur(n, m, x, y + 1, k, i, 3);
					}
					else
					{
						newyork_recur(n, m, x, y + 1, k - 1, i, 3);
					}
					if (prev == 4)
					{
						newyork_recur(n, m, x, y - 1, k, i, 4);
					}
						else
					{
						newyork_recur(n, m, x, y - 1, k - 1, i, 4);
					}
				}
			}
		}
	}
}

int NewYork(int n, int m, int k)
{
		int count = 0;
		newyork_recur(n-1, m-1, 0, 0, k, &count,0);
		return count;
	
}