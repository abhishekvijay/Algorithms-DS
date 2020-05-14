
#include <stdio.h>
#include <iostream>

using namespace std;

int normal_fnum(int n)
{
	cout<<"for - "<<n<<endl;

	if (n <= 1)
		return n;
	
	return (normal_fnum(n-1) + normal_fnum(n-2));
}

int lookup[501];
void finit(void)
{
	register int i;
	for(i=0; i<=500; ++i)
		lookup[i] = -1;
}
int memoized_fnum(int n)
{

	if (lookup[n] == -1)
	{
		if (n <= 1)
			return n;
		else
			lookup[n] = memoized_fnum(n-1) + memoized_fnum(n-2);
	}
	return lookup[n];
}

int tabular_fnum(int n)
{
	int arr[501];
	register int i;
	
	arr[0] = 0; arr[1] = 1;
	for(i=2; i<=500; ++i)
		arr[i] = arr[i-1] + arr[i-2];

	return arr[n];
}

void fibonacci_num()
{
	int num = 100;

	finit();

	cout<<"Num - "<<num<<"Normal fibonacci num - "<<normal_fnum(num)<<endl;

	cout<<"Num - "<<num<<" Memoized fibonacci num - "<<memoized_fnum(num)<<endl;

	cout<<"Num - "<<num<<" Tabular fibonacci num - "<<tabular_fnum(num)<<endl;

	cout<<endl;

	return;
}