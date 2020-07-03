
#include <stdio.h>

static int count;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void partition(int arr[], int lb, int ub, int *val)
{
	int llb = lb;
	int uub = ub;
	int a = arr[lb];

	while (llb < uub)
	{
		while ((arr[llb] <= a) && (llb < uub))
			llb++;
		while (arr[uub] > a)
			uub--;

		if (llb < uub)
			swap(&arr[llb], &arr[uub]);
	}
	arr[lb] = arr[uub];
	arr[uub] = a;
	*val = uub;
}

void normal_quickSort(int arr[], int st, int en)
{
	count++;

	if (en <= st)
		return;

	int j = 0;

	partition(arr, st, en, &j);

	normal_quickSort(arr, st, j-1);

	normal_quickSort(arr, j+1, en);
}

void quick_sort(int *ptr, int sz)
{
	normal_quickSort(ptr, 0, sz);

	return;
}