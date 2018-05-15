/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

5
/ \
2   3
\
30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

9
/ \
4   1
/     \
20      30
Nodes 1 and 20 need to be fixed here .

*/


//#include <stdio.h>
//#include <stdlib.h>
//
//void inorder_array(struct node *root, int *arr, int *i);
//void searching_defects_in_array(int *arr, int *i, int *j, int len);
//
//struct node{
//	struct node * left;
//	int data;
//	struct node *right;
//};
//
//void inorder_array(struct node *root, int *arr, int *i)
//{
//	if (root != NULL)
//	{
//		inorder_array(root->left, arr, i);
//		arr[(*i)++] = root->data;
//		inorder_array(root->right, arr, i);
//	}
//}
//
//void replacing(struct node *root, int defect1, int defect2)
//{
//	if (root != NULL)
//	{
//		if (root->data == defect1)
//			root->data = defect2;
//		else if (root->data == defect2)
//			root->data = defect1;
//		replacing(root->left, defect1, defect2);
//		replacing(root->right, defect1, defect2);
//	}
//}
//
//void searching_defects_in_array(int *arr, int *i, int *j, int len)
//{
//	while ((*i) + 1 < len)
//	{
//		if (arr[*i] > arr[(*i) + 1])
//			break;
//		(*i)++;
//	}
//
//	while ((*j) - 1 >= 0)
//	{
//		if (arr[*j] < arr[(*j) - 1])
//			break;
//		(*j)--;
//	}
//}
//
//
//
//void fix_bst(struct node *root)
//{
//	if (root == NULL)
//		return;
//
//	int *arr = (int *)malloc(sizeof(int) * 100);
//	int i, j, len;
//
//	i = 0;
//	struct node *n = root;
//	inorder_array(n, arr, &i);
//
//	len = i; i = 0; j = len - 1;
//	searching_defects_in_array(arr, &i, &j, len);
//
//	int defect1, defect2;
//	defect1 = arr[i];
//	defect2 = arr[j];
//
//	replacing(root, defect1, defect2);
//}
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
void search(int *a, int *j, int *k, int i);
void find2(struct node * root, int i, int j);
void insert(struct node * root, int *a, int *i);
void insert(struct node * root, int *a, int *i){
	if (root != NULL)
	{
		insert(root->left, a, i);
		a[(*i)++] = root->data;
		insert(root->right, a, i);
	}
}
void find2(struct node * root, int i, int j)
{
	if (root != NULL)
	{

		if (root->data == i)
		{
			root->data = j;
		}
		else if(root->data==j)
		{
			root->data=i;
		}
		find2(root->left, i, j);
		find2(root->right, i, j);
	}
}
void search(int *a, int *j, int *k, int i){
	while ((*j) + 1 < i)
	{
		if (a[*j] > a[(*j) + 1])
		{
			break;
			(*j)++;
		}
	}
	while ((*k) - 1 >= 0)
	{
		if (a[*k] < a[(*k) - 1])
		{
			break;
			(*k)--;
		}
	}
}
void fix_bst(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		struct node *n = root;
		int * a = (int *)malloc(sizeof(int) * 100);
		int i = 0;
		insert(n, a, &i);
		int j = 0, k = i - 1;
		/*int *j, *k;
		j = 0;
		k = &(i);
		(*k)--;*/
		int l, m, flag = 0;
		/*while ((*j) + 1 < i)
		{
			if (a[*j] > a[(*j) + 1])
			{
				break;
				(*j)++;
			}
		}
		while ((*k) - 1 >= 0)
		{
			if (a[*k] < a[(*k) - 1])
			{
				break;
				(*k)--;
			}
		}*/
	//	search(a, &j, &k, i);
		for ( j = 0; j < i; j++)
		{
			for (k = i - 1; k > j; k--)
			{
				if (a[j] > a[k])
				{
					l = j, m = k;
					flag = 1;
					break;
				}
			}
			if (flag==1)
			{
				break;
			}
		}
		l = a[j], m = a[k];
		find2(root, l,m);
	}
}
