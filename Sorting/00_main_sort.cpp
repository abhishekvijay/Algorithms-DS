#if 0

#include <stdio.h>

#define MAX			10

#define PRINT(X,A)	do { \
						printf(X); \
						for(register int i=0; i<MAX; ++i) \
							printf("%d ", A[i]); \
						printf("\n"); \
					} while(0); \

//Bubble Sort
extern void iter_bubble_sort(int *ptr, int st, int en);
extern void recur_bubble_sort(int *ptr, int sz);
extern void opt_bubble_sort(int *ptr, int st, int en);

//Merge Sort
extern void merge_sort_recur(int *ptr, int st, int en);
extern void merge_sort_iter(int *ptr, int st, int en);

int main()
{
	int arr[MAX] = {67,100,32,91,61,72,89,45,12,34};
	int sz = MAX-1;
	
	PRINT("Before - ",arr);

	iter_bubble_sort(arr, 0, sz);
	recur_bubble_sort(arr, sz);
	opt_bubble_sort(arr, 0, sz);

//	merge_sort_recur(arr, 0, sz);
//	merge_sort_iter(arr, 0, sz);

	PRINT("After - ", arr);	
	return 0;
}

#endif