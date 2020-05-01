
#if 0

#include <stdio.h>

#define MAX			11

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int *ptr, int i, int sz)
{
	int l = 2*i;
	int r = 2*i+1;
	int lgst = 0;

	if (l <= sz && ptr[l] > ptr[i])
		lgst = l;
	else 
		lgst = i;

	if (r <= sz && ptr[r] > ptr[lgst])
		lgst = r;

	if (lgst != i)
	{
		swap(&ptr[lgst], &ptr[i]);
		max_heapify(ptr, lgst, sz);
	}
}

void create_heap(int *ptr, int sz)
{
	register int i;

	for (i=(sz/2); i>=1; i--)
		max_heapify(ptr, i, sz);
}

void sort_heap(int *ptr, int sz)
{
	register int i;
	int cnt = sz-1;

	for(i=cnt; i>=2; i--)
	{
		swap(&ptr[1], &ptr[i]);
		cnt -= 1;
		max_heapify(ptr, 1, cnt);
	}
}

void heap_sort_recur(int *ptr, int sz)
{
	if (ptr == NULL)
		return;

	create_heap(ptr, sz);

	sort_heap(ptr, sz);
}

int main()
{
	int arr[MAX] = {0,12,67,34,98,45,72,11,59,24,38};
	int sz = MAX;

	heap_sort_recur(arr, sz);

	register int i;
	for(i=1; i<MAX; ++i)
		printf("%d ", arr[i]);

	return 0;
}



#endif

