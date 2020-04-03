

#include <stdio.h>

void selection_sort2(int *ptr, int lb, int ub)
{
	register int i, j;
	int small, indx;

	for(i=ub; i>0; i--)
	{
		small = ptr[0];
		indx = 0;

		for(j=1; j<=i; ++j)
		{
			if (ptr[j] < small)
			{
				small = ptr[j];
				indx = j;
			}
		}
		ptr[indx] = ptr[i];
		ptr[i] = small;
	}
	return;
}

void selection_sort(int *ptr, int lb, int ub)
{
	register int i, j;
	int large, indx;

	for(i=ub; i>0; i--)
	{
		large = ptr[0];
		indx = 0;

		for(j=1; j<=i; ++j)
		{
			if (ptr[j] > large)
			{
				large = ptr[j];
				indx = j;
			}
		}
		ptr[indx] = ptr[i];
		ptr[i] = large;
	}
	return;
}

int main()
{
	int arr[10] = {10,27,82,45,12,36,79,59,31,9};

//	selection_sort(arr, 0, 9);

	selection_sort2(arr, 0, 9);

	for(register int i = 0; i<10; ++i)
		printf("%d ", arr[i]);

	return 0;
}