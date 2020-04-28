
#if 1

#include <stdio.h>

void mswap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void partition(int *OrgPtr, int lb, int ub, int *val)
{
	int *ptr = OrgPtr;
	int llb = lb, uub = ub, item = ptr[lb];

	while(llb < uub)
	{
		while(ptr[llb] <= item && llb < uub)
			llb++;
		while(ptr[uub] > item)
			uub--;

		if (llb < uub)
			mswap(&ptr[llb], &ptr[uub]);
	}
	OrgPtr[lb] = ptr[uub];
	ptr[uub] = item;
	*val = uub;

	return;
}

void recursive_qsort(int *OrgPtr, int lb, int ub)
{
#if 0 //traditional recursive algo
	if (ub <= lb)
		return;

	int j = 0;

	partition(OrgPtr, lb, ub, &j);

	traditional_qsort(OrgPtr, lb, j-1);

	traditional_qsort(OrgPtr, j+1, ub);
#else //optimized solution with less function calls
	int j = 0;

	while(lb < ub)
	{		
		partition(OrgPtr, lb, ub, &j);

		recursive_qsort(OrgPtr, lb, j-1);

		lb = j+1;
	}
#endif
}

/*===================================================================*/

typedef struct bndtype {
	int lb;
	int ub;
} boundtype;

typedef struct staick {
	int top;
	boundtype bounds[100]; //MAX bnds
} stack;

void push(stack *stck, boundtype obj)
{
	stck->bounds[++stck->top] = obj;
}

void pop(stack *stck, boundtype *obj)
{
	*obj = stck->bounds[stck->top--];
}

int empty(stack *stck)
{
	return (stck->top == -1) ? 1 : 0;
}

void iterative_qsort(int *OrgPtr, int lb, int ub)
{
	stack stck;
	boundtype newbnds;
	int j = 0, i = 0;

	stck.top = -1;
	newbnds.lb = lb;
	newbnds.ub = ub;

	push(&stck, newbnds);

	while(!empty(&stck))
	{
		pop(&stck, &newbnds);

		while(newbnds.lb < newbnds.ub)
		{
			partition(OrgPtr, newbnds.lb, newbnds.ub, &j);

			if (j - newbnds.lb > newbnds.ub - j)
			{
				//stack lower subarray
				i = newbnds.ub;
				newbnds.ub = j-1;
				push(&stck, newbnds);
				//process upper subarray
				newbnds.lb = j+1;
				newbnds.ub = i;
			}
			else
			{
				//stack upper subarray
				i = newbnds.lb;
				newbnds.lb = j+1;
				push(&stck, newbnds);
				//process lower subarray
				newbnds.lb = i;
				newbnds.ub = j-1;
			}
		}
	}
	return;
}

void quick_sort(int *ptr, int sz)
{
#if 0
	recursive_qsort(ptr, 0, sz-1);
#else
	iterative_qsort(ptr, 0, sz-1);
#endif
	return;
}

int main()
{
	int arr[10] = {23,16,12,89,34,75,99,62,92,45};

	quick_sort(arr, 10);

	for(register int i=0; i<10; ++i)
		printf("%d ", arr[i]);

	return 0;
}


#endif