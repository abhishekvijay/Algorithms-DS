
#include <stdio.h>

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a%b);
}

void rev_elements(int *ptr, int st, int en)
{
	int temp;

	while(st < en)
	{
		temp = ptr[st];
		ptr[st] = ptr[en];
		ptr[en] = temp;
		st++;
		en--;
	}
	return;
}

void rev_arr(int *ptr, int sz, int d)
{
	if (d == 0)
		return;
	rev_elements(ptr, 0, d-1);
	rev_elements(ptr, d, sz-1);
	rev_elements(ptr, 0, sz-1);
}

void rot_arr(int *ptr, int sz, int d)
{
	register int i;
	int temp, _gcd;

	_gcd = gcd(sz, d);

	if (_gcd == 1)
	{
		while(d > 0)
		{
			temp = ptr[0];
			for(i=0; i<sz-1; ++i)
				ptr[i] = ptr[i+1];
			ptr[i] = temp;
			d -= 1;
		}
	}
	else
	{
		rev_arr(ptr, sz, d);
	}
	return;
}

void print(int *ptr, int sz)
{
	register int i;

	for(i=0; i<sz; ++i)
		printf("%d ", ptr[i]);
	printf("\n");	
}

void rotate_array()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int barr[7] = {1,2,3,4,5,6,7};
	int carr[2] = {1,2};
	int darr[2] = {1, 2};

	int asz = 10, bsz = 7, csz = 2;
	int da = 3, db = 2, dc1 = 1, dc2 = 1;

	rot_arr(arr, asz, da);
		print(arr, asz);
	rot_arr(barr, bsz, db);
		print(barr, bsz);
	rot_arr(carr, csz, dc1);
		print(carr, csz);
	rot_arr(darr, csz, dc2);
		print(darr, csz);

	return;
}