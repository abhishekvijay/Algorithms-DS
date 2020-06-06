
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX(a,b)	(a>b)?a:b

/*================================================================= recursive knapsack */

int rec_knapsack(int *val, int *wt, int w, int sz)
{
	if (!val || !wt)
		return 0;
	if (sz == 0 || w == 0)
		return 0;	

	if (wt[sz-1] <= w)
	{
		return MAX((val[sz-1] + rec_knapsack(val, wt, w-wt[sz-1], sz-1)), rec_knapsack(val, wt, w, sz-1));
	}
	else 
		return rec_knapsack(val, wt, w, sz-1);	
}

/*================================================================= memoized knapsack */

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
	if (!val || !wt)
		return 0;
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

/*================================================================= tabular knapsack */

int tabular_knapsack(int *val, int *wt, int w, int sz)
{
	if (!val || !wt)
		return 0;
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

/*================================================================= knapsack queries */

int qlup[5][11];
void qinit()
{
	for(int i=0; i<5; ++i)
		for(int j=0; j<11; ++j)
			qlup[i][j] = -1;
}
int get_query_result(int *w, int W, int n)
{
	if (!w)
		return 0;
#if 0 //recursive

	if (n==0 || W==0)
		return 0;	

	if (w[n-1] <= W)
		return MAX(w[n-1] + get_query_result(w, W-w[n-1], n-1), get_query_result(w, W, n-1));
	else
		return get_query_result(w, W, n-1);

#elseif 0 //memoized

	if (n == 0 || W == 0)
		return 0;

	if (qlup[n][W] != -1)
		return qlup[n][W];

	if (w[n-1] <= W)
		qlup[n][W] = MAX(w[n-1] + get_query_result(w, W-w[n-1], n-1), get_query_result(w, W, n-1));
	else
		qlup[n][W] = get_query_result(w, W, n-1);

	return qlup[n][W];

#else //tabular

	int t[4][12] = {0,};
	int i, j;

	for(i=0,j=0; i<4; ++i)
		t[i][j] = 0;
	for(j=0,i=0; j<12; ++j)
		t[i][j] = 0;

	for(i=1; i<4; ++i)
	{
		for(j=1; j<12; ++j)
		{
			if (w[i-1] <= W)
				t[i][j] = MAX(w[i-1] + t[i-1][j-w[i-1]], t[i-1][j]);
			else
				t[i][j] = t[i-1][j];
		}
	}
	cout<<endl;
	return t[n][W];
#endif
}

void knapsack_queries()
{
	int w[] = {3,8,9};
	int q[] = {11,10,4};
	int sz = sizeof(w)/sizeof(w[0]);

	register int i;
	for(i=0; i<sz; ++i)
	{
		cout<<"query for - "<<q[i]<<" = "<<get_query_result(w,q[i],sz)<<endl;
	}
}

/*================================================================= fractional knapsack */

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
	return (int)finalVal;
}

/*================================================================= unbounded fractional KS */

double ubf_knapsack()
{
	float val[] = { 14, 27, 44, 19 }; 
    float wt[] = { 6, 7, 9, 8 }; 
    int n = sizeof(val) / sizeof(val[0]); 
    int W = 50; 

	float maxratio = INT_MIN; 
    int maxindex = 0; 

	for (int i = 0; i < n; i++) 
	{ 
        if ((val[i] / wt[i]) > maxratio) 
		{
            maxratio = (val[i] / wt[i]); 
            maxindex = i; 
        } 
    }		
	return (W * maxratio);
}

/*================================================================= subset sum */
void subset_sum()
{

}

/*================================================================= equal sum partition */
void equal_sum_partition()
{

}

/*================================================================= count of subset sum */
void count_subset_sum()
{

}

/*================================================================= mimimum subset sum difference */
void min_subset_sum_diff()
{

}

/*================================================================= target sum */
void target_sum()
{

}

/*================================================================= main function */

void knapsack_01()
{
	int val[3] = {60,100,120};
	int wt[3] = {10,20,30};
	int W = 50;	

	/* recursive ks */
	cout<<"recur - "<<rec_knapsack(val, wt, W, 3)<<endl;

	/* memoized ks */
	init_ks();
	cout<<"memoized - "<<memoized_knapsack(val, wt, W, 3)<<endl;

	/* tabular ks */
	cout<<"tabular - "<<tabular_knapsack(val, wt, W, 3)<<endl;	

	/* unbounded ks */
	cout<<"ubounded ks - "<<ub_knapsack()<<endl;

	/* branch_bound_knapsack */

	/* print items in 0-1 knapsack */

	/* print all possible solution */

	/* 0-1 knapsack queries */
	qinit();
	knapsack_queries();

	/* knapsack with large weights */

	/* fractional */
	cout<<"fractional - "<<frac_knapsack()<<endl;

	/* unbounded fractional */
	cout<<"unbounded fractional - "<<ubf_knapsack()<<endl;
	
	//fractional knapsack queries

	/* subset sum */
	subset_sum();

	/* equal sum partition */
	equal_sum_partition();

	/* count of subset sum */
	count_subset_sum();

	/* mimimum subset sum difference */
	min_subset_sum_diff();

	/* target sum */
	target_sum();

	//No. of subsets in given difference

	cout<<endl;

	return;
}
