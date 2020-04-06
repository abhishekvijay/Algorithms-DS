

#include <stdio.h>

/*
createHeap - applying queue insertion pqinsert().
sortHeap - applying pqmaxdelete() from reverse order.
*/

void createHeap(int *ptr, int st, int en)
{
	if (en <= st)
		return; //invalid params

	register int i;
	int s, f, val;

	for(i=1; i<=en; i++)
	{
		val = ptr[i];

		s = i;
		f = (s-1)/2;

		while (s>0 && ptr[f] < val)
		{
			ptr[s] = ptr[f];
			s = f;
			f = (s-1)/2;
		}

		ptr[s] = val;
	}

	return;
}

void sortHeap(int *ptr, int st, int en)
{
	if (en <= st)
		return;

	register int i;
	int s, f, val;

	for(i = en; i>0; i--)
	{
		val = ptr[i];
	}
}

int main()
{
	int arr[8] = {25,57,48,37,12,92,86,33};

	createHeap(arr, 0, 7);

	sortHeap(arr, 0, 7);

	for(register int i=0; i<8; ++i)
		printf("%d ", arr[i]);

	return 0;
}