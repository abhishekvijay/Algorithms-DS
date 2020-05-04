#if 0

#include <stdio.h>

/*
createHeap - applying queue insertion pqinsert().
sortHeap - applying pqmaxdelete() from reverse order.
*/

void create_heap(int *ptr, int st, int en)
{
	if (en <= st)
		return;

	register int i;
	int val, s, f;

	for(i=1; i<=en; i++)
	{
		val = ptr[i];

		s = i;
		f = (s-1)/2;

		while(s>0 && ptr[f] < val)
		{
			ptr[s] = ptr[f];
			s = f;
			f = (s-1)/2;
		}

		ptr[s] = val;
	}
	return;
}

void sort_heap(int *ptr, int st, int en)
{
	if (en <= st)
		return;

	register int i;
	int val, s, f;

	for(i=en; i>0; i--)
	{
		val = ptr[i];
		ptr[i] = ptr[0];
		f = 0;

		/*largeson -> (0-->i-1)*/
		(i==1) ? (s=-1) : (s=1);

		if (i>2 && ptr[2]>ptr[1])  ///mistake
			s = 2;

		while(s>=0 && ptr[s] > val) ///mistake
		{
			ptr[f] = ptr[s];
			f= s;
			s = 2*f+1;			

			if (s+1 <= i-1 && ptr[s] < ptr[s+1])
				s += 1;

			if (s > i-1)
				s = -1;
		}
		ptr[f] = val;
	}
}

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

		while (s > 0 && ptr[f] < val)
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
		ptr[i] = ptr[0];

		f = 0;

		/*finding largeson - 0, i-1*/
		if (i == 1)
			s = -1;
		else
			s = 1;

		if ( i > 2 && ptr[2] > ptr[1])
			s = 2;

		while (s>=0 && val < ptr[s])
		{
			ptr[f] = ptr[s];
			f = s;

			s = 2*f+1;

			if (s+1 <= i-1 && ptr[s] < ptr[s+1])
				s = s+1;

			if (s > i-1)
				s = -1;
		}

		ptr[f] = val;
	}
	return;
}

int main()
{
	int arr[8] = {25,57,48,37,12,92,86,33};

	//createHeap(arr, 0, 7);
	create_heap(arr, 0, 7);

	//sortHeap(arr, 0, 7);
	sort_heap(arr, 0, 7);

	for(register int i=0; i<8; ++i)
		printf("%d ", arr[i]);

	return 0;
}

#endif