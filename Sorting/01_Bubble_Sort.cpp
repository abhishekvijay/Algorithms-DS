
#include <stdio.h>

#define SWAP(x,y)	do { int temp = *x; *x = *y; *y = temp; } while(0);


void opt_bubble_sort(int *ptr, int st, int en)
{
	if (en <= st)
		return;

	int *ptr1 = ptr;
	int pass, i;
	int IsFound = 1;

	for(pass = 0; pass < en && IsFound; ++pass)
	{
		IsFound = 0;

		for(i=0; i<en-pass; ++i) //applied opitmization
		{
			if (ptr1[i] > ptr1[i+1])
			{
				IsFound = 1;
				SWAP(&ptr1[i], &ptr1[i+1]);
			}
		}
	}
}

void recur_bubble_sort(int *ptr, int sz)
{
	if (sz == 1)
		return;

	for(register int i=0; i<sz; ++i)
		if (ptr[i] > ptr[i+1])
			SWAP(&ptr[i], &ptr[i+1]);

	recur_bubble_sort(ptr, sz-1);
}

void iter_bubble_sort(int *ptr, int st, int en)
{
	if (en <= st)
		return;

	int *ptr1 = ptr;
	int IsFound = 1;
	int i = 0;

	while(IsFound) {
		IsFound = 0;
		for(i = 0; i < en; ++i)
		{
			if (ptr1[i] > ptr1[i+1])
			{
				SWAP(&ptr1[i], &ptr1[i+1]);
				IsFound = 1;
			}
		}
	}
	return;
}