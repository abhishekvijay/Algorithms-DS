
#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void partition(int arr[], int lb, int ub, int *val)
{
	int pv = (ub-lb+1)>>1;
	int a = arr[pv];//arr[lb];
	int llb = lb;
	int uub = ub;

	while(llb < uub)
	{
		while(arr[llb] <= a && llb < uub)
		{
			llb++;

			if ((arr[llb] < arr[llb-1]) && (llb-1 >= lb))
				swap(&arr[llb], &arr[llb-1]);			
		}
		while(arr[uub] > a)
		{
			uub--;

			if ((arr[uub] > arr[uub+1]) && (uub+1 <= ub))
				swap(&arr[uub], &arr[uub+1]);
		}

		if (llb < uub) {
			swap(&arr[llb], &arr[uub]);

			if ((arr[llb] < arr[llb-1]) && (llb-1 >= lb))
				swap(&arr[llb], &arr[llb-1]);

			if ((arr[uub] > arr[uub+1]) && (uub+1 <= ub))
				swap(&arr[uub], &arr[uub+1]);
		}
	}
	//arr[pv] = arr[uub];
	arr[lb] = arr[uub];
	arr[uub] = a;
	*val = uub;
}


void BSort(int arr[], int st, int en)
{
	if (en <= st)
		return;

	int j = 0;

	partition(arr, st, en, &j);

	BSort(arr, st, j-1);

	BSort(arr, j+1, en);
}

int main()
{
	int arr[10] = {23,45,12,89,34,75,99,62,92,16};

	BSort(arr, 0, 9);

	for(register int i = 0; i<10; ++i)
		printf("%d ", arr[i]);

	return 0;
}