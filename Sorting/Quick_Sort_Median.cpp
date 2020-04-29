
#if 0

#include <stdio.h>

#define MAX		100

/*##################################################################*/
#if 0

void mswap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void partition(int arr[], int st, int en, int *val)
{
	int lb = st;
	int ub = en;
	int pv = (ub+lb)/2;

	int itm = arr[pv];

	while(lb < ub)
	{
		while(arr[lb] <= itm )//&& lb < ub)
			lb++;
		while(arr[ub] > itm)
			ub--;

		if (lb < ub) {
			mswap(&arr[lb], &arr[ub]);
			lb++; ub--;
		}
	}
//	arr[pv] = arr[ub];
//	arr[ub] = itm;
	*val = ub;
}

void sort_median(int arr[], int st, int en)
{
	if (en <= st)
		return;

	int j = 0;

	partition(arr, st, en, &j);

	sort_median(arr, st, j-1);

	sort_median(arr, j+1, en);
}

#else
/*##################################################################*/

typedef struct BOUNDS {
	int lb;
	int ub;
} Bounds;

typedef struct STAICK {
	int top;
	Bounds bnds[MAX];
} Stack;

void push(Stack *ptr, Bounds obj)
{
	ptr->bnds[++ptr->top] = obj;
}

void pop(Stack *ptr, Bounds *bobj)
{
	*bobj = ptr->bnds[ptr->top--];
}

int IsEmpty(Stack *ptr)
{
	return (ptr->top == -1) ? 1 : 0;
}

void mswap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void partition(int arr[], int st, int en, int *val)
{
	int lb = st;
	int ub = en;
	int a = arr[lb];

	while(lb < ub)
	{
		while(arr[lb] <= a && lb < ub)
			lb++;
		while(arr[ub] > a)
			ub--;

		if (lb < ub)
			mswap(&arr[lb], &arr[ub]);
	}
	arr[st] = arr[ub];
	arr[ub] = a;
	*val = ub;
}

void sort_median(int arr[], int st, int en)
{
	Stack stck;
	Bounds bnds;
	int j = 0, i = 0;

	stck.top = -1;
	bnds.lb = st;
	bnds.ub = en;

	push(&stck, bnds);

	while(!IsEmpty(&stck))
	{
		pop(&stck, &bnds);

		while(bnds.lb < bnds.ub)
		{
			partition(arr, bnds.lb, bnds.ub, &j);

			if (j-bnds.lb > bnds.ub-j)
			{
				i = bnds.ub;
				bnds.ub = j-1;
			
				push(&stck, bnds);

				bnds.lb = j+1;
				bnds.ub = i;
			}
			else
			{
				i = bnds.lb;
				bnds.lb = j+1;

				push(&stck, bnds);

				bnds.ub = j-1;
				bnds.lb = i;
			}
		}
	}
}

#endif

int main()
{
	int arr[MAX] = {10,2,40,32,12,97,1,15,19,78};

	sort_median(arr, 0, 9);

	for(register int i = 0; i<10; ++i)
		printf("%d ", arr[i]);

	return 0;
}



#endif