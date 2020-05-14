
#include <stdio.h>
#include <iostream>

using namespace std;

int calc_NcR(int n, int k)
{
	register int i;
	int num = 1;

	if (k == 0)
		return 1;
	else if (k == 1)
		return n;

	for(i=1; i<=k; ++i)
	{
		num *= (n-i+1);
		num /= i;
	}
	return num;
}

void catalan_num(void)
{
	int ans = calc_NcR(8, 2);

	cout<<"Val - "<<ans;

	cout<<endl;

	return;
}
