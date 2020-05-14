

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX		1000+1

int arr[MAX] = {0, };

int get_ugly(int n)
{
	int cnt = 1, i = 0, j = 1;

	while (cnt <= n)
	{
		i = j;

		while(i%2 == 0)
			i = i/2;
		while(i%3 == 0)
			i = i/3;
		while(i%5 == 0)
			i = i/5;

		if (i == 1)
			arr[cnt++] = j;

		j += 1;
	}
	return arr[n];
}

void ugly_numbers()
{
	int n;

	cout<<"Enter num - ";
	cin>>n;

	cout<<"ugly no - "<<get_ugly(n);

	cout<<endl;

	return;
}