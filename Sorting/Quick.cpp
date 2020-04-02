
#include <stdio.h>

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
	if (en <= st)
		return;

	int j = 0;

	partition(arr, st, en, &j);

	quickSort(arr, st, j-1);

	quickSort(arr, j+1, en);
}


int main()
{
	int arr[10] = {23,45,12,89,34,75,99,62,92,16};

	quickSort(arr, 0, 9);

	for(register int i=0; i<10; ++i)
		printf("%d ", arr[i]);

	return 0;
}