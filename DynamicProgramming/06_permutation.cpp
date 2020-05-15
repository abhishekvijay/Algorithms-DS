
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

void permutation_coeff(void)
{
	cout<<"iter - "<<iter_perm(8,2)<<endl;

	cout<<"rec - "<<rec_perm(8,2)<<endl;

	cout<<endl;

	return;
}