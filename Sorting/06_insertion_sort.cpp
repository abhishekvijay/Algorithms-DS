
#include <stdio.h>

void insertion_sort(int *ptr, int sz)
{
	if (!ptr || sz == 0)
		return;

	int val, i, j;	

	for(i=1; i<sz; i++)
	{
		val = ptr[i];

		for(j=i-1; j>=0 && ptr[j]>val; j--)
				ptr[j+1] = ptr[j];
		ptr[j+1] = val;
	}
}
