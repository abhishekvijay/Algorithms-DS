
#include <stdio.h>

#define MAX		100

/* never to use array representaiton of BT while using sorting
reason - too much space is wasted, better use linked implementation */

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

void createTreeLkd(int *ptr, int st, int en)
{
	return;
}

int main()
{
	int arr[10] = {10,15,2,40,78,21,19,68,32,9};

//	createTreeArr(arr, 0, 9);

	createTreeLkd(arr, 0, 9);

//	inOrderTraverse();

	return 0;
}