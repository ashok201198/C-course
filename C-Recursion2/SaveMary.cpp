/*

	Raju bhai is a new don in town. He enjoys hanging people every weekend.
	This weekend he assembled N people in a circular manner (1,2,..N,1) and choosen a random integer K. 
	He framed certain rules to hang people.
	
	Rule 1: He skips K-1 persons (inclusive) and hang Kth person.
	Rule 2: He always starts counting from 1st person.
	Rule 3: The last person will be allowed to live for rest of his life.
	
	Sample Case:
		Given N=5, K=2
			Initial state: 1,2,3,4,5
		Step 1: skips 1 and hangs 2
			1,3,4,5
		Step 2: Now skips 3 and hangs 4
			1,3,5
		Step 3: Now skips 5 and hangs 1
			3,5
		Step 4: Now skips 3 and hangs 5
			3
		As 3 is only person, he lets him live.

	Save our friend Mary by choosing correct position in the initial circle.
	You have to return the integer x, such that if mary is positioned at x in [1..N] she
	will not be killed, if no such position exists, return -1
	Fill the below function with code and return the postion.
	Return -1 for error cases
*/
#include<stdio.h>
#include<stdlib.h>
void rec(int * a, int n, int k, int p, int c){
	if (c == 1)
	{
		return;
	}
	else
	{
		c--;
		int r = 0;
		while (r != k)
		{
			if (a[p] != 1)
			{
				p++;
			}
			else if (a[p] == 1)
			{
				p++; r++;
			}
			if (p>n)
			{
				p = 1;
			}
		}
		//p++;
		while (a[p] != 1)
		{
			p++;
			if (p>n)
			{
				p = 1;
			}
		}
		if (a[p] == 1)
		{
			a[p] = 0;
		}
		rec(a, n, k, p, c);
	}
}
int saveMary(int n, int k){
	if (n < 0 || k < 1 || n<k)
	{
		return -1;
	}
	else
	{
		int i;
		int * a = (int *)malloc(sizeof(int)*(n + 1));
		for (i = 1; i <= n; i++){
			a[i] = 1;
		}
		rec(a, n, k - 1, 1, n);
		for (i = 1; i <= n; i++)
		{
			if (a[i] == 1)
			{
				break;
			}
		}
		return i;
	}
}
