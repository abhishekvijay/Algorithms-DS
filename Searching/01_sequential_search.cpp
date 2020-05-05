
#include <stdio.h>
#include <malloc.h>

#define MAX			30
#define MAX1		MAX-10

void arr_sequential_srch()
{
	int arr[MAX] = {12,34,56,78,90,98,87,65,54,43,21,14,16,46,89,41,61,81,66,99}; //large size

	register int i;
	int item = 41;

	for(i = 0; i<MAX; ++i)
	{
		if (arr[i] == item)
			break;
	}

	if (i == MAX-1)
		printf("item not found");

	printf("found item - %d at location %d havin value %d", item, i, arr[i]);
}

void arr_optmz_seq_srch()
{

}

/*###############################################################################################*/

typedef struct NODES
{
	int val;
	NODES *nxt;
} Nodes;

typedef struct HEADER
{
	int cnt;
	Nodes *list;
} Header;

Header head;

Nodes *getNode(int val)
{
	Nodes *node = NULL;
	node = (Nodes *)malloc(sizeof(Nodes));
	if (node != NULL)
	{
		node->nxt = 0;
		node->val = val;
	}
	return node;
}

void init_list()
{
	head.cnt = 0;
	head.list = 0;
}

void append_list(int val)
{
	Nodes *p, *q;
	register int i;

	if (head.list != 0)
	{
		for(p = head.list; p != NULL; p = p->nxt)
			q = p;

		q->nxt = getNode(val);		
	}
	else
		head.list = getNode(val);

	head.cnt += 1;
	return;
}

void populate_list(int *ptr)
{
	register int i;

	for(i=0; i<MAX1; ++i)
		append_list(*ptr++);

	return;
}

void list_sequential_srch()
{
	int arr[MAX1] = {12,34,56,78,90,98,87,65,54,43,21,14,16,46,89,41,61,81,66,99};

	init_list();

	populate_list(arr);	

	return;
}

void list_optmz_seq_srch()
{

}