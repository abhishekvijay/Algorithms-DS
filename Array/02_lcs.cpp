
#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX(a,b)		(a>b)?a:b;

/* conditions - (i < j); (j % i = 0); (arr[i] < arr[j]) */
void lcs_with_conditions()
{
	int arr[6] = {1,2,3,7,9,10};

	int i, j, dp[7], ans = 0;
	for(i=0; i<7; ++i)
		dp[i] = 1;

	for(i=1; i<=7; ++i)
	{
		for(j=2*i; j<=7; j+=i)
		{
			if (arr[j] > arr[i])
				dp[j] = MAX(dp[j], dp[i] + 1)
		}

		ans = MAX(ans, dp[i]);
	}
	cout<<"answer - "<<ans<<endl;
}


void lcs()
{
	/* conditions - (i < j); (j % i = 0); (arr[i] < arr[j]) */
	lcs_with_conditions();

	return;
}