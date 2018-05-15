/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:

Binary Search :

Conclusion :
*/

int linearSearch(int *arr, int len, int key) {

	for (int i = 0; i < len; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}

	return -1;

}
int bs(int *arr, int low, int high, int key);
int binarySearch(int *arr, int len, int key)
{
	int low = 0;
	int high = len - 1;
	int k = bs(arr, low, high, key);
	return k;
}
int bs(int *arr, int low, int high, int key)
{
	int mid = (low + high) / 2;
	if (low > high)
	{
		return -1;
	}
	if (low <= high)
	{
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] > key)
		{
			return bs(arr, low, mid - 1, key);
		}
		else if (arr[mid] < key)
		{
			return bs(arr, mid + 1, high, key);
		}
		else return -1;

	}

}