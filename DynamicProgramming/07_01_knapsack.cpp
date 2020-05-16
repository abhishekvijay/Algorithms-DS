

#include <iostream>

using namespace std;

#define MAX(a,b)	(a>b)?a:b

int rec_knapsack(int *val, int *wt, int w, int sz)
{
	if (sz == 0 || w == 0)
		return 0;	

	if (wt[sz-1] <= w)
	{
		return MAX((val[sz-1] + rec_knapsack(val, wt, w-wt[sz-1], sz-1)), rec_knapsack(val, wt, w, sz-1));
	}
	else 
		return rec_knapsack(val, wt, w, sz-1);	
}

int kst[5][55]; //table should be of the form - [n+1][w+1]
void init_ks()
{
	for(int i =0; i<5; ++i)
		for(int j = 0; j<55; ++j)
			kst[i][j] = -1;
	return;
}
int memoized_knapsack(int *val, int *wt, int w, int sz)
{
	if (sz == 0 || w == 0)
		return 0;

	if (kst[sz][w] != -1)
		return kst[sz][w];

	if (wt[sz-1] <= w)
		kst[sz][w] = MAX((val[sz-1] + memoized_knapsack(val, wt, w-wt[sz-1], sz-1)), memoized_knapsack(val, wt, w, sz-1));
	else
		kst[sz][w] = memoized_knapsack(val, wt, w, sz-1);	

	return kst[sz][w];
}

int tabular_knapsack(int *val, int *wt, int w, int sz)
{
	return 0;
}

void knapsack_01()
{
	int val[3] = {60,100,120};
	int wt[3] = {10,20,30};
	int W = 50;	

	cout<<"recur - "<<rec_knapsack(val, wt, W, 3)<<endl;

	init_ks();
	cout<<"memoized - "<<memoized_knapsack(val, wt, W, 3)<<endl;

	cout<<"tabular - "<<tabular_knapsack(val, wt, W, 3)<<endl;

	cout<<endl;

	return;
}