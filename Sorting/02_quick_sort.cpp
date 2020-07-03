
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

void quickSort_Opt1(int arr[], int st, int en)
{
	count++;

	int j = 0;

	while (st < en)
	{
		partition(arr, st, en, &j);

		quickSort_Opt1(arr, st, j-1);

		st = j+1;
	}
}

void quickSort_Opt2(int arr[], int st, int en)
{
	count++;

	int j = 0;

	while (st < en)
	{
		partition(arr, st, en, &j);

		if (j-st < en-j)
		{
			quickSort_Opt2(arr, st, j-1);
			st = j+1;
		}
		else
		{
			quickSort_Opt2(arr, j+1, en);
			en = j-1;
		}
	}
}

void quickSort_Opt3(int arr[], int st, int en)
{
	return;
}

void quick_sort(int *ptr, int sz)
{
	//normal implementation
	normal_quickSort(ptr, 0, sz);

	//removed one recursive call
	quickSort_Opt1(ptr, 0, sz);

	//using recursion based on which side is smaller
	quickSort_Opt2(ptr, 0, sz);

	//using middle element as pivot
	quickSort_Opt3(ptr, 0, sz);

	return;
}