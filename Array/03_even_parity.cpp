
#include <stdio.h>
#include <iostream>

using namespace std;


void even_parity()
{
	int range[2][2] = {{1,10},{121,211}};
	int prefix_sum[1001] = {0, };
	int cnt = 0;

	register int i, j;

	int min = 999999, max = 99, even_p = 0;

	for(i=0; i<2; ++i)
	{
		if (range[i][0] < min)
			min = range[0][i];
		if (range[i][1] > max)
			max = range[i][1];
	}

	for(i=1; i<=max; ++i)
	{
		j = i; cnt = 0;
		while(j)
		{
			j &= (j-1);
			cnt++;
		}

		if (cnt%2 == 0)
			even_p = i;
		else
			even_p = 0;

		prefix_sum[i] = prefix_sum[i-1] + even_p;
	}

	cout<<"50 - "<<prefix_sum[10]-prefix_sum[0]<<" 1000 - "<<prefix_sum[211] - prefix_sum[120]<<endl;
}