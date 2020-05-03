
#include <stdio.h>

#define SWAP(x,y)	do { int temp = *x; *x = *y; *y = temp; } while(0);


void optimized_bubble_sort(int arr[], int st, int en)
{
	if (en <= st)
		return;

	int *ptr = arr;
	int pass, i;
	int IsFound = 1;

	for(pass = 0; pass < en-1 && IsFound; ++pass)
	{
		IsFound = 0;

		for(i=0; i<en-pass-1; ++i) //applied opitmization
		{
			if (ptr[i] > ptr[i+1])
			{
				IsFound = 1;
				SWAP(&ptr[i], &ptr[i+1]);
			}
		}
	}
}

void sort_bubble(int arr[], int st, int en)
{
	if (en <= st)
		return;

	int *ptr = &arr[0];
	int IsFound = 1;
	int i = 0;

	while(IsFound) {
		IsFound = 0;
		for(i = 0; i < en-1; ++i)
		{
			if (ptr[i] > ptr[i+1])
			{
				SWAP(&ptr[i], &ptr[i+1]);
				IsFound = 1;
			}
		}
	}
	return;
}