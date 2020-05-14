
#include <stdio.h>
#include <iostream>

using namespace std;

int bi_coeff_iter(int n, int k)
{
	return 0;
}

int bi_coeff_rec(int n, int k)
{
	if (k == 0 || k == n)
		return 1;

	return (bi_coeff_rec(n-1, k-1) + bi_coeff_rec(n-1, k));
}

int t[20][20];

void bc_init()
{
	register int i, j;

	for(i=0; i<20; ++i)
		for(j=0; j<20; ++j)
			t[i][j] = -1;
}

int bi_coeff_memoized(int n, int k)
{
	if (t[n][k] != -1)
		return t[n][k];

	if (k=0 || k==n) {
		t[n][k] = 1;
		return t[n][k];
	}

	t[n][k] = bi_coeff_memoized(n-1, k-1) + bi_coeff_memoized(n-1, k);

	return t[n][k];
}

void binomial_coeff(void)
{
	//cout<<"bi-coeff - "<<bi_coeff_iter(5,2)<<endl;

	cout<<"bi-coeff - "<<bi_coeff_rec(5,2)<<endl;

	bc_init();
	cout<<"bi-coeff - "<<bi_coeff_memoized(5,2)<<endl;

	cout<<endl;

	return;
}
