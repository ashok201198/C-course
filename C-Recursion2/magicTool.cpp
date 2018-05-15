/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/
#include <malloc.h>
#include<stdio.h>
struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};


void select(char *pixels, int x, int y, int m, int n, char p, result* res, int *i, struct Point*c)
{
	if (x < m  && y < n && x >= 0 && y >= 0){
		if (pixels[(x*n) + (y)] == p&&res->visited[(x*n) + (y)] == false)
		{
			res->visited[(x*n) + (y)] = true;
			c->x = x;
			c->y = y;
			res->selected[(*i)] = *c;
			(*i)++;
			res->size++;
		}
		else
		{
			res->visited[(x*n) + (y)] = true;
		}
		if (res->visited[(x*n) + (y - 1)] == false && pixels[(x*n) + (y - 1)] == p)
		{
			select(pixels, x, y - 1, m, n, p, res, i, c);
		}
		if (res->visited[(x*n) + (y + 1)] == false && pixels[(x*n) + (y + 1)] == p)
		{
			select(pixels, x, y + 1, m, n, p, res, i, c);
		}
		if (res->visited[((x - 1)*n) + (y)] == false && pixels[((x - 1)*n) + (y)] == p)
		{
			select(pixels, x - 1, y, m, n, p, res, i, c);
		}
		if (res->visited[((x + 1)*n) + (y)] == false && pixels[((x + 1)*n) + (y)] == p)
		{
			select(pixels, x + 1, y, m, n, p, res, i, c);
		}
		// feel free to change this function parameters
	}
}
struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {
	struct result *res = (struct result *)malloc(sizeof(struct result));
	res->size = 0;
	if (pixels == NULL)
	{
		return *res;
	}
	if (m<0&&n<0)
	{
		return *res;
	}
	if ((pivot.x>m)||(pivot.y>n) || (pivot.x<0)||(pivot.y<0))
	{
		return *res;
	}
	else
	{
		m++; n++;
		res->selected = (struct Point *)malloc(sizeof(Point)*(m*n));
		res->visited = (bool *)malloc(sizeof(bool)*(m*n));
		Point *c = (struct Point*)malloc(sizeof(Point));
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				res->visited[(i*n) + j] = false;
			}
		}
		int nx = pivot.x;
		int ny = pivot.y;
		char p=pixels[(nx*n)+ny];
		int i = 0;
		select(pixels,nx,ny,m,n, p, res,&i,c);
		return *res;
	}
}
