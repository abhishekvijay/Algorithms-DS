
#include <stdio.h>

//Bubble Sort
extern void sort_bubble(int arr[], int st, int en);
extern void optimized_bubble_sort(int arr[], int st, int en);


int main()
{
	int arr[10] = {67,100,32,91,61,72,89,45,12,34};

//	sort_bubble(arr, 0, 10);
	optimized_bubble_sort(arr, 0, 10);

	for(register int i=0; i<10; ++i)
		printf("%d ", arr[i]);

	return 0;
}