/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
int gheight(struct node * node)
{
	if (node == NULL)
		return 0;

	int lefth = gheight(node->left);
	int righth = gheight(node->right);
	if (lefth > righth){
		return 1 + lefth;
	}

	return 1 + righth;
}
int dist(struct node * root, struct node * temp)
{
	int i = 0;
	while (root != temp){
		if (root->data > temp->data)
		{
			root = root->left;
		}
		else if (root->data < temp->data)
		{
			root = root->right;
		}
		i++;
	}
	return i;
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
	{
		return -1;
	}
	else
	{
		int h,cd,min=INT_MAX;
		int d = dist(root, temp);
		int t = gheight(temp)-1;
		while (root != temp)
		{
			if (root->data> temp->data)
			{
				h = gheight(root->left)-1;
				root = root->left;
			}
			if (root->data < temp->data)
			{
				h = gheight(root->right)-1;
				root = root->right;
			}
			if (d + h < t)
			{
				cd = d + h;
			}
			else
			{
				cd = t;
			}
			if (min>cd)
			{
				min = cd;
			}
		}
		return min/2+1;
	}
}