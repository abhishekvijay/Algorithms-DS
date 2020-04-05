
#include <stdio.h>

#define MAX		100

/* never to use array representaiton of BT while using sorting
reason - too much space is wasted, better use linked implementation */

typedef struct TREENODE
{
	int val; 
	int use;
}TNode;

TNode tree[MAX];

void makeTree(int val)
{
	tree[0].val = val;
	tree[0].use = 1;

	for(register int i=1; i<MAX; ++i)
	{
		tree[i].use = 0;
		tree[i].val = 0;
	}
	return;
}

void setLeft(int p, int val)
{
	int q = 2*p+1;

	printf("pos[%d], val[%d]\n", q, val);

	if (q>=MAX)
		return; //overflow
	else if (tree[q].use == 1)
		return; //duplicate
	else
	{
		tree[q].val = val;
		tree[q].use = 1;
	}
	return;
}

void setRight(int p, int val)
{
	int q = 2*p+2;

	printf("pos[%d], val[%d]\n", q, val);

	if (q >= MAX)
		return; //overflow
	else if (tree[q].use == 1)
		return; //duplicate
	else
	{
		tree[q].val = val;
		tree[q].use = 1;
	}
	return;
}

void createTree(int *ptr, int st, int en)
{
	register int i;

	makeTree(ptr[0]);

	int p, q, val;

	for (i=1; i<=en; ++i)
	{
		val = ptr[i];
		p = q = 0;

		while(q < MAX && tree[q].use)
		{
			p = q;

			if (val < tree[q].val)
				q = 2*p+1;
			else
				q = 2*p+2;
		}

		if (val < tree[p].val)
			setLeft(p, val);
		else
			setRight(p, val);
	}
}

int main()
{
	int arr[10] = {10,15,2,40,78,21,19,68,32,9};

	createTree(arr, 0, 9);

//	inOrderTraverse();

	return 0;
}