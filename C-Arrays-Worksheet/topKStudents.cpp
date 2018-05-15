/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
Problem Code :TK
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
}temp;
void swap(struct student *students, int len);
struct student ** topKStudents(struct student *students, int len, int K) {
	int i, j;
	if (students!=NULL&&len>0&&K>0)
	{ 
		swap(students,len);
		struct student **send = (struct student **)malloc(sizeof(struct student)*K);
		if (K < len)
		{
			for (i = 0; i < K; i++)
			{
				send[i] = &students[i];
			}
		}
		else
		{
			for (j = 0; j < len; j++)
			{
				send[j] = &students[j];
			}
		}
		return send;
	}
	else return NULL;
}
void swap(struct student *students, int len)
{
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = i; j < len; j++)
		{
			if (students[i].score < students[j].score)
			{
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}