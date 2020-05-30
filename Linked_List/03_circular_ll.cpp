

#include <stdio.h>
#include <malloc.h>

#define MAX				10

typedef struct NODE
{
	int data;
	NODE *next;
}Node;

typedef struct CLIST
{
	int count;
	Node *list;
	Node *end;
}Clist;

Clist head;

void init()
{
	head.count = 0;
	head.list = NULL;
	head.end = NULL;
}

Node *getNode(int item)
{
	Node *nd = NULL;
	nd = (Node *)malloc(sizeof(Node));
	if (nd != NULL)
	{
		nd->data = item;
		nd->next = 0;
	}
	return nd;
}

void insert_list(int item)
{
	Node *list = head.list;

	if (list == NULL)
	{
		list = getNode(item);
		list->next = list;
		head.list = list;
	}
	else
	{
		Node *hd = list;	

		while(list->next != hd)
			list = list->next;

		Node *newNode = getNode(item);
		newNode->next = hd;
		list->next = newNode;		

		head.end = newNode;
	}
	return;
}

void print_list(Node *ll)
{
	Node *list = NULL;

	(ll == 0) ? list = head.list : list = ll;

	Node *hd = list;

	while(list->next != hd)
	{
		printf("%d ", list->data);
		list = list->next;
	}
	printf("%d \n\n", list->data);

	return;
}

void split_list(const int sz)
{
	Node *list = head.list;

	if (list == 0)
		printf("invalid list\n");

	Node *hd = list, *tortoise = list, *hare = list;
	int cnt = 2;

	do {
		cnt += 2;
		tortoise = tortoise->next->next;
		hare = hare->next;
	} while (tortoise != hd && cnt < sz);

	if ((sz % 2) == 0)
		tortoise = tortoise->next;

	Node *list1 = head.list, *list2 = head.list, *temp = NULL;
	
	temp = hare->next;	
	hare->next = list1;

	list2 = temp;
	tortoise->next = list2;

	print_list(list1);
	print_list(list2);

	return;
}

void circular_linked_list()
{
	register int i;
	int arr[MAX] = {10,39,14,6,57,69,84,77,21,32};

	/* initialize list */
	init();

	/* insert list */
	for(i = 0; i<MAX; ++i)
		insert_list(arr[i]);

	/* print list */
	print_list(NULL);

	/* split list */
	split_list(MAX);

	/* binary tree to circular list */
	/* josephus problem */
	/* deque implementation */

	return;
}
