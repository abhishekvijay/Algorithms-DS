
#include <iostream>
#include <algorithm>

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
	register int i, j;
	int t[4][51] = {0, };

	for(i=0,j=0; i<4; ++i)
		t[i][j] = 0;
	for(j=0,i=0; j<51; ++j)
		t[i][j] = 0;

	for(i=1; i<4; ++i)
	{
		for(j=1; j<51; ++j)
		{
			if (wt[i-1] <= w)
				t[i][j] = MAX(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
			else
				t[i][j] = t[i-1][j];
		}
	}
	return t[sz][w];
}

typedef struct ITEM {
	int val; 
	int wt;
}Item;

bool ks_compare(Item a, Item b)
{
	double r1 = double(a.val/a.wt);
	double r2 = double(b.val/b.wt);

	return r1>r2;
}

int frac_knapsack(void)
{
	Item arr[] = {{60,10}, {100,20}, {120,30}};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int W = 50;

	sort(arr, arr+sz, ks_compare);

	int currWt=0;
	double finalVal=0;

	for(int i=0; i<sz; ++i)
	{
		if (currWt + arr[i].wt <= W)
		{
			currWt += arr[i].wt;
			finalVal += arr[i].val;
		}
		else
		{
			int remain = W - currWt;
			finalVal += arr[i].val*(double(remain)/arr[i].wt);
			break;
		}
	}
	return finalVal;
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

	cout<<"fractional - "<<frac_knapsack()<<endl;

	cout<<endl;

	return;
}