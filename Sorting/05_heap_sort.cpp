
#include <stdio.h>

#define ri		register int

int getlargeSon(int *ptr, int p, int m)
{
	int s = 2*p + 1;
	if (s+1 <= m && ptr[s] < ptr[s+1])
		s = s+1;
	if (s > m)
		return -1;
	else
		return s;
}

void rec_adjustHeap(int *ptr, int root, int k)
{
	int f = root;
	int s = getlargeSon(ptr, f, k-1);

	if (s >= 0 && ptr[k] < ptr[s])
	{
		ptr[f] = ptr[s];
		rec_adjustHeap(ptr, s, k);
	}
	else
		ptr[f] = ptr[k];
}

void iter_adjustHeap(int *ptr, int root, int k)
{
	int f = root;
	int val = ptr[k];
	int s = getlargeSon(ptr, f, k-1);

	while(s >= 0 && val < ptr[s])
	{
		ptr[f] = ptr[s];
		f = s;
		s = getlargeSon(ptr, f, k-1);
	}
	ptr[f] = val;
}

void heap_sort(int *ptr, int sz)
{
	if (ptr == NULL || sz <= 0)
		return;
	
	int f, s, item, i;
	//pqinsert operation
	for(ri i = 1; i < sz; ++i)
	{
		item = ptr[i];
		s = i;
		f = (s-1)/2;

		while(s > 0 && ptr[f] < item)
		{
			ptr[s] = ptr[f];
			s = f;
			f = (s-1)/2;
		}

		ptr[s] = item;
	}

	//pqmaxdelete operation
	for(i = sz; i > 0; --i)
	{
		f = ptr[0];
		//rec_adjustHeap(ptr, 0, sz);
		iter_adjustHeap(ptr, 0, sz);
		printf("%d ", f);
	}

	return;
}