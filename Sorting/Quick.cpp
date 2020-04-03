
#include <stdio.h>

static int count = 0;

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

void quickSort(int arr[], int st, int en)
{
	count++;

	if (en <= st)
		return;

	int j = 0;

	partition(arr, st, en, &j);

	quickSort(arr, st, j-1);

	quickSort(arr, j+1, en);
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

int main()
{
	int arr[10] = {23,45,12,89,34,75,99,62,92,16};

//	quickSort(arr, 0, 9);

//	quickSort_Opt1(arr, 0, 9);

	quickSort_Opt2(arr, 0, 9);

	for(register int i=0; i<10; ++i)
		printf("%d ", arr[i]);

	printf("\n count - %d \n", count);

	return 0;
}