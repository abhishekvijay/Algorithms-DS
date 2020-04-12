
#if 1

#include <stdio.h>

#define ri		register int

void shell_sort(int *ptr, int st, int en)
{
	if (en <= st)
		return;

	ri i, j, k;
	int val = 0, span = 0;
	int incr[4] = {7, 5, 3, 1};

	for(i=0; i<4; i++)
	{
		span = incr[i];

		for(j=span; j<en; j++)
		{
			val = ptr[j];

			for(k=j-span; k>=0 && ptr[k]>val; k-=span)
				ptr[k+span] = ptr[k];

			ptr[k+span] = val;
		}
	}
	return;
}

int main()
{
	int arr[10] = {32,96,12,41,6,56,89,77,64,21};

	shell_sort(arr, 0, 10);

	for (ri i=0; i<10; i++)
		printf("%d ", arr[i]);

	return 0;
}

#endif