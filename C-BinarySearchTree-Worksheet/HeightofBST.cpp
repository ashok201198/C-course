/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void get(struct node * root,int h,int *p)
{
	if (root != NULL)
	{
		h++;
		get(root->left, h, p);
		get(root->right, h, p);
	}
	else if (root == NULL)
	{
		if (h > *p)
		{
			*p = h;
		}
	}
}
void getsuml(struct node * root, int *i)
{
	if (root != NULL)
	{
		(*i) = (*i) + root->data;
		getsuml(root->left, i);
		getsuml(root->right, i);
	}
	else if (root == NULL){ return; }
}
void getsumr(struct node * root, int *i)
{
	if (root != NULL)
	{
		(*i) = (*i) + root->data;
		getsumr(root->left, i);
		getsumr(root->right, i);
	}
	else if (root == NULL){ return; }
}
int get_height(struct node *root){
	if (root != NULL)
	{
		int i = 0;
		get(root,0,&i);
		return i;
	}
	return 0;
}

int get_left_subtree_sum(struct node *root){
	if (root != NULL)
	{
		int l = 0;
		getsuml(root->left,&l);
		return l;
	}
	else return -1;
}

int get_right_subtree_sum(struct node *root){
	if (root != NULL)
	{
		int l = 0;
		getsumr(root->right, &l);
		return l;
	}
	else return -1;
}

