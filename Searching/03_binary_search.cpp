
#include <stdio.h>

#define MAX		20
#define SWAP(x,y)		do { int temp = *x; *x = *y; *y = temp; } while(0);

// bubble sort
void csort(int *ptr, int sz)
{
	register int i, j;
	int IsFound = 1;

	for(i=0; i<sz && IsFound; i++)
	{
		IsFound = 0;

		for(j=0; j<sz-i; ++j)
		{
			if (ptr[j] > ptr[j+1])
			{
				IsFound = 1;
				SWAP(&ptr[j], &ptr[j+1]);
			}
		}
	}
	return;
}

/*
 *  Iterative Version
 */
int iter_bs(int *ptr, int item, int sz)
{
	int mid = 0, lo = 0, hi = sz+1;	

	while(lo < hi)
	{
		mid = (lo + hi) >> 1;

		if (item == ptr[mid])
			return mid;
		else if (item < ptr[mid])
			hi = mid - 1;
		else
			lo = mid + 1;
	}

	if (ptr[mid] == item)
		return mid;
	else
		return -1;
}

void iter_binary_srch()
{
	int arr[MAX] = {12,34,56,78,90,98,87,65,54,43,21,14,16,46,89,41,61,81,66,99};

	csort(arr, MAX-1);

	int itm = 99;

	printf("item srch - %d, found at index - %d\n", itm, iter_bs(arr, itm, MAX-1));	

	return;
}

/*
 *  Recursive Version
 */
int recur_bs(int *ptr, int item, int lb, int ub)
{
	int mid = 0;

	if (ub < lb)
		return -1;

	mid = (lb + ub) >> 1;

	return ((item == ptr[mid]) ? mid : ((item < ptr[mid]) ? recur_bs(ptr, item, lb, mid-1) : recur_bs(ptr, item, mid+1, ub)));
}

void recur_binary_srch()
{
	int arr[MAX] = {12,34,56,78,90,98,87,65,54,43,21,14,16,46,89,41,61,81,66,99};

	csort(arr, MAX-1);

	int itm = 99;

	printf("item srch - %d, found at index - %d\n", itm, recur_bs(arr, itm, 0, MAX));	

	return;
}
