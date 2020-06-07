#include <iostream>
#include <algorithm>

using namespace std;

#define MAX(a,b)	(a>b)?a:b

/*================================================================= unbounded KS */
int ub_knapsack()
{
	int val[] = {10,30,20};
	int wt[] = {5,10,15};
	int W = 100;
	int sz = sizeof(val)/sizeof(val[0]);

	int t[101] = {-1, };

	for(int i=0; i<=W; ++i)
	{
		for(int j=0; j<sz; ++j)
		{
			if (wt[j] <= i)
				t[i] = MAX(t[i], t[i-wt[j]]+val[j]);
		}
	}
	return t[W];
}

void unbounded_knapsack()
{
	int val[3] = {60,100,120};
	int wt[3] = {10,20,30};
	int W = 50;	

	/* unbounded ks */
	cout<<"ubounded ks - "<<ub_knapsack()<<endl;

	cout<<endl;

	return;
}
