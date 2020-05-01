
#if 1

#include <stdio.h>

#define MAX			11

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void maxheapify(int *ptr, int i, int sz)
{
	int l = 2*i;
	int r = 2*i+1;
	int lgst = 0;

	if (l<=sz && ptr[l] > ptr[i])
		lgst = l;
	else
		lgst = i;

	if (r<=sz && ptr[r] > ptr[lgst])
		lgst = r;

	if (lgst != i)
	{
		swap(&ptr[i], &ptr[lgst]);
		maxheapify(ptr, lgst, sz);
	}
}

void create_heap(int *ptr, int sz)
{
	register int i;

	for(i=(sz/2); i>=1; i--)
		maxheapify(ptr, i, sz);
}

void sort_heap(int *ptr, int sz)
{
	register int i,j;
	int cnt = sz-1;

	for(i=cnt; i>=2; i--)
	{
		swap(&ptr[1], &ptr[i]);
		cnt -= 1;
		maxheapify(ptr, 1, cnt);
	}

	int temp[MAX]; 
	j = 1;
	cnt = sz-1;

	for(i=cnt; i>=1; i--)
		temp[j++] = ptr[i];
	for(i=1; i<=cnt; ++i)
		ptr[i] = temp[i];

	return;
}

void heap_sort(int *ptr, int sz)
{
	if (ptr == NULL)
		return;

	create_heap(ptr, sz);

	sort_heap(ptr, sz);
}

int get_maximum(int *ptr, int sz)
{
	return ptr[1];
}

int extract_maxm(int *ptr, int sz)
{
	if (!ptr)
		return -1; //invalid params

	int cnt = sz-1;

	int max = ptr[1];
	ptr[1] = ptr[cnt];
	cnt -= 1;
	maxheapify(ptr, 1, cnt);

	return max;
}

void insert_val(int *ptr, int val, int sz)
{
	int cnt = sz-1;
	ptr[cnt] = val;
	
	while(cnt>1 && ptr[cnt/2] < ptr[cnt])
	{
		swap(&ptr[cnt/2], &ptr[cnt]);
		cnt = cnt/2;
	}
}

void max_pq(int *ptr, int sz)
{
	int max1 = get_maximum(ptr, sz);
	printf("Maximum1 - %d\n", max1);

//	int max2 = extract_maxm(ptr, sz);
//	printf("Maximum2 - %d\n", max2);

	int val = 110;
	insert_val(ptr, val, sz+1);
}

int main()
{
	int arr[MAX] = {0,24,56,89,91,34,44,23,71,62,78};

	heap_sort(arr, MAX);

	max_pq(arr, MAX);

//	min_priority_queue();

	return 0;
}

#endif