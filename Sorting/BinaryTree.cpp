#if 0
#include <stdio.h>
#include <malloc.h>

#define MAX		100

/* never to use array representaiton of BT while using sorting
reason - too much space is wasted, better use linked implementation */

/*####################################################################*/

typedef struct TREENODEARR
{
	int val; 
	int use;
}TNodeArr;

TNodeArr tree[MAX];

void makeTreeArr(int val)
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

void setLeftArr(int p, int val)
{
	int q = 2*p+1;

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

void setRightArr(int p, int val)
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

void createTreeArr(int *ptr, int st, int en)
{
	if (ptr == 0)
		return; //invalid array

	register int i;

	makeTreeArr(ptr[0]);

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
			setLeftArr(p, val);
		else
			setRightArr(p, val);
	}
}

/*####################################################################*/

typedef struct TREENODELKD {
	int val;
	TREENODELKD *lft;
	TREENODELKD *rgt;
} TNodeLkd;

TNodeLkd *treeLkd = 0;

TNodeLkd* addNode(int x)
{
	TNodeLkd *node = (TNodeLkd *)malloc(sizeof(TNodeLkd));
	if (node != 0) {
		node->val = x;
		node->lft = 0;
		node->rgt = 0;
	}
	return node;
}

void setLeftLkd(TNodeLkd *tree, int x)
{
	if (tree == 0)
		return; //invalid tree
	else if (tree->lft != 0)
		return; //already occupied
	else 
		tree->lft = addNode(x);
	return;
}

void setRightLkd(TNodeLkd *tree, int x)
{
	if (tree == 0)
		return; //invalid tree
	else if (tree->rgt != 0)
		return; //already occupied
	else
		tree->rgt = addNode(x);
	return;
}

void createTreeLkd(int *ptr, int st, int en)
{
	treeLkd = addNode(ptr[st]);

	TNodeLkd *p=0, *q=0;
	int val;

	for(register int i = 1; i<=en; ++i)
	{
		val = ptr[i];
		p = q = treeLkd;

		while(q != 0)
		{
			p = q;
			if (val < p->val)
				q = p->lft;
			else
				q = p->rgt;
		}

		if (val < p->val)
			setLeftLkd(p, val);
		else
			setRightLkd(p, val);
	}
}

void inOrderTraverse(TNodeLkd *ptr)
{
	if (ptr == 0)
		return;

	inOrderTraverse(ptr->lft);

	printf("%d ", ptr->val);

	inOrderTraverse(ptr->rgt);
}

void deleteTree(TNodeLkd *ptr)
{
	if (ptr == 0)
		return;

	deleteTree(ptr->lft);
	deleteTree(ptr->rgt);
	printf(" %d", ptr->val);
	free(ptr); ptr = NULL;
}

/*####################################################################*/

int main()
{
	int arr[10] = {10,15,2,40,78,21,19,68,32,9};

//	createTreeArr(arr, 0, 9);

	createTreeLkd(arr, 0, 9);

	inOrderTraverse(treeLkd);

	printf("\n");

	deleteTree(treeLkd);

	return 0;
}

#endif