/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
//void recur(int n,char *c,int *cc,int *pc)
//{
//	if (*cc == 2)
//	{
//		//if (*pc == 1)
//		//{
//		//	if (*cc == 1){
//		//		*c = 'A';
//		//	}
//		//	else if (*cc == 2){
//		//		*c = 'B';
//		//	}
//		//	else if (*cc == 3){
//		//		*c = 'C';
//		//	}
//		//}
//		//else if(*pc == 2)
//		//{
//		//	if (*cc == 1){
//		//		*c = 'B';
//		//	}
//		//	else if (*cc == 2){
//		//		*c = 'C';
//		//	}
//		//	else if (*cc == 3){
//		//		*c = 'A';
//		//	}
//		//}
//		//else if (*pc == 3)
//		//{
//		//	if (*cc == 1){
//		//		*c = 'C';
//		//	}
//		//	else if (*cc == 2){
//		//		*c = 'A';
//		//	}
//		//	else if (*cc == 3){
//		//		*c = 'B';
//		//	}
//		//}
//		*pc = n;
//	}
//	else
//	{
//		if (n > 9){ n = n % 9; }
//		if (n == 0){ n = 9; }
//		/*if (n > 1)
//		{
//			n--;
//			(*cc)++;
//			if (*cc == 4)
//			{
//				(*pc)++;
//				*cc = 1;
//			}
//			if ((*pc) == 4)
//			{
//				(*pc) = 1;
//			}
//		}*/
//		(*cc)++;
//		recur(n, c, cc, pc);
//	}
//}
char recurs(int n, int k){
	if (n == 1)
	{
		return 'A';
	}
	else
	{
		int c;
		char aarr[4] = "ABC";
		char barr[4] = "BCA";
		char carr[4] = "CAB";
		n--;
		if (k % 3 == 0)
		{
			k = k / 3;
			c = 3;
		}
		else
		{
			c = k % 3;
			k = k / 3;
			k++;
		}
		char x = recurs(n, k);
		if (x == 'A')
		{
			return aarr[c - 1];
		}
		else if (x == 'B')
		{
			return barr[c - 1];
		}
		else if (x == 'C')
		{
			return carr[c - 1];
		}
	}
}
char identifyKid(int N, int K) {
	if (N==0||K==0)
	{
		return '\0';
	}
	double i = 3;
	if (K > pow(i, N - 1))
	{
		return '\0';
	}
	else 
	{
		char c = recurs(N, K);
		return c;
	}
}