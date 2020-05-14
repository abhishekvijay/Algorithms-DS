

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX		200+1

int arr[MAX] = {0, };

int get_ugly(int n)
{
	int cnt = 1, i = 0, j = 1;

	while (cnt <= n)
	{
		i = cnt;

		while(i%2 == 0)
			i = i/2;
		while(i%3 == 0)
			i = i/3;
		while(i%5 == 0)
			i = i/5;

		if (i == 1)
			arr[j++] = cnt;

		cnt += 1;
	}
	return arr[n];
}

void ugly_numbers()
{
	int n;

	cout<<"Enter num - ";
	cin>>n;

	cout<<", ugly no - "<<get_ugly(n)<<endl;
	return;
}