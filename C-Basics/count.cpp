/*
OVERVIEW:  Given 2 integers (num1, num2), write a function that returns the count of numbers between the num1..num2 that are divisible by num1.
		E.g.: count(3, 15) returns 5 (3, 6, 9, 12, 15).
		Note : You need to consider Inclusive range
INPUTS:  Two numbers num1, num2.
		num1, num2 >= 0.

OUTPUT: Return the count of numbers between the num1..num2 that are divisible by num1.

ERROR CASES: Return -1 in error cases.

NOTES:
*/
int count(int num1, int num2) {
	int m = num1;
	int n = num2;
	int i,c=0;
	if (m == 0)
		return -1;
	if (n == 0)
		return 0;
	if (m >= 0 && n >= 0)
	{
		if (m < n)
		{
			for (i = m; i <= n; i++)
			{
				if (i%m == 0)
				{
					c++;
				}
			}
			return c;
			}
		else return 0;
	}
	else
		return -1;
}