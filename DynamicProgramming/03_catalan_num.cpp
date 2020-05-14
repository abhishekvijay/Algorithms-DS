
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

int cat[11] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int calc_catalan(int n)
{
	int num = 0;

#if 1  //DP Solution  
    cat[0] = cat[1] = 1;       
    for (int i=2; i<=n; i++) 
    { 
        cat[i] = 0; 
        for (int j=0; j<i; j++) 
            cat[i] += cat[j] * cat[i-j-1]; 
    }      
    return cat[n];

#else //Normal solution

	if (n <= 1) return 1;
	for(int i=0; i<n; i++)
		num += calc_catalan(i)*calc_catalan(n-i-1);	
	return num;
#endif
	
}

void catalan_num(void)
{
	int ans = calc_NcR(8, 2);

	cout<<"NcR value - "<<ans<<endl;

	ans = calc_catalan(9);  //calculates nth catalan no.

	cout<<"catalan value - "<<ans;

	cout<<endl;

	return;
}
