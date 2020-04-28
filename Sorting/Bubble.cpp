#if 1
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

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
				swap(&ptr[i], &ptr[i+1]);
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
				swap(&ptr[i], &ptr[i+1]);
				IsFound = 1;
			}
		}
	}
	return;
}

int main()
{
	int arr[10] = {67,100,32,91,61,72,89,45,12,34};

	//sort_bubble(arr, 0, 10);
	optimized_bubble_sort(arr, 0, 10);

	for(register int i=0; i<10; ++i)
		printf("%d ", arr[i]);

	return 0;
}
#endif