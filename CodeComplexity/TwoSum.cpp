/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion :
*/
#include <stdio.h>
#include <stdlib.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? __________
*/
int* sumoftwoBF(int *nums, int target, int len){
	int *arr = (int *)malloc(sizeof(int) * 2);
	if (nums != NULL&&len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (i != j)
				{
					if (nums[i] + nums[j] == target)
					{
						if (nums[i]>nums[j])
						{
							arr[0] = nums[j];
							arr[1] = nums[i];
						}
						else
						{
							arr[0] = nums[i];
							arr[1] = nums[j];
						}
						return arr;
					}
				}
			}
		}
	}
	else return NULL;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? __________
*/
void sort(int *nums, int low, int high);
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	if (nums == NULL)
	{
		return NULL;
	}
	sort(nums, 0, len - 1);
	int i = 0, j = len - 1;
	while (i < j)
	{
		if ((nums[i] + nums[j]) == target)
		{
			int *x = (int *)malloc(sizeof(int) * 2);
			x[0] = nums[i];
			x[1] = nums[j];
			return x;
		}
		if ((nums[i] + nums[j]) > target)
			j--;
		if ((nums[i] + nums[j]) < target)
			i++;
	}
	return NULL;
}

void sort(int *nums, int low, int high)
{
	int pivot, i, j;
	if (low < high)
	{
		pivot = low;
		i = low + 1;
		j = high;
		while (i < j)
		{
			while (nums[i] <= nums[pivot] && i <= high)
			{
				while (nums[pivot] == nums[i])
					i++;
				if (nums[pivot] > nums[i])
				{
					int temp = nums[pivot];
					nums[pivot] = nums[i];
					nums[i] = temp;
					pivot++;
					i++;
				}
			}
			while (nums[pivot] < nums[j])
				j--;
			if (i < j)
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
		sort(nums, low, pivot - 1);
		sort(nums, j + 1, high);
	}
}
/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/
int* sumoftwoExtraArray(int *nums, int target, int len)
{	
	int *req = (int *)malloc(sizeof(int) * 101);
	for (int i = 0; i <= 100; i++)
	{
		req[i] = 0;
	}
	int *a = (int *)malloc(sizeof(int) * 2);
	for (int i = 0; i < len; i++)
	{
		int x = nums[i];
		if (x < target)
		{
			if ((x + req[x]) == target)
			{
				if (x > req[x])
				{
					a[0] = req[x];
					a[1] = x;
				}
				else
				{
					a[1] = req[x];
					a[0] = x;
				}
				return a;
			}
			else
			{
				req[target - x] = x;
			}
		}
	}

}


