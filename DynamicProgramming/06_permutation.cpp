
#include <iostream>

using namespace std;

int iter_perm(int n, int k)
{
	int ans = 1;

	for(int i = 1; i<=k; ++i)
		ans *= (n-i+1);

	return ans;
}

int rec_perm(int n, int k)
{
	if (k > n) //different condition
		return 0;

	if (k == 0)
		return 1;

	return (rec_perm(n-1,k) + k*rec_perm(n-1,k-1));
}

int lookup[30][30];
void p_init()
{
	register int i, j;
	for(i=0; i<30; ++i)
		for(j=0; j<30; ++j)
			lookup[i][j] = -1;
	return;
}

int memoized_perm(int n, int k)
{
	if (lookup[n][k] != -1)
		return lookup[n][k];

	if (k == 0)
	{
		lookup[n][k] = 1;
		return lookup[n][k];
	}

	if (n < k)
	{
		lookup[n][k] = 0;
		return lookup[n][k];
	}

	lookup[n][k] = memoized_perm(n-1,k) + k*memoized_perm(n-1,k-1);

	return lookup[n][k];
}

int tabular_perm(int n, int k)
{
	register int i, j;
	int t[30][30] = {0, };

	for(i=0; i<=n; ++i)
	{
		for(j=0; j<=((i<k)?i:k); ++j)
		{
			if (j>i)
				t[i][j] = 0;

			if (j==0)
				t[i][j] = 1;
			else
				t[i][j] = t[i-1][j] + j*t[i-1][j-1];			
		}
	}

	return t[n][k];
}

void permutation_coeff(void)
{
	cout<<"iter - "<<iter_perm(8,2)<<endl;

	cout<<"rec - "<<rec_perm(8,2)<<endl;

	p_init();
	cout<<"memoized - "<<memoized_perm(8,2)<<endl;

	cout<<"tabular - "<<tabular_perm(8,2)<<endl;

	cout<<endl;

	return;
}