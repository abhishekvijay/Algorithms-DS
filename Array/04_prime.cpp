
#include <stdio.h>
#include <iostream>

using namespace std;

void efficient_prime(int n)
{
	if (n <= 1) {
		cout<<"n - "<<n<<" not prime"<<endl;
		return;
	}
	if (n <= 3) {
		cout<<"n - "<<n<<" is prime"<<endl;
		return;
	}

	if ((n%2 == 0) || (n%3 == 0)) {
		cout<<"n - "<<n<<" not prime"<<endl;
		return;
	}

	for(auto i = 5; i*i<n; i+=6) {
		if ((n%i==0) || (n%(i+2)==0)) {
			cout<<"n - "<<n<<" not prime"<<endl;
			return;
		}
	}

	cout<<"n - "<<n<<" is prime"<<endl;
	return;
}

void check_prime(int n)
{
	if (n <= 1) {
		cout<<"n - "<<n<<" not prime"<<endl;
		return;
	}

	for(auto i = 2; i<n; ++i)
	{
		if (n%i == 0) {
			cout<<"n - "<<n<<" not prime"<<endl;
			return;
		}
	}

	cout<<"n - "<<n<<" is prime"<<endl;
	return;
}

void is_prime()
{
	int arr[11] = {2,3,4,5,6,7,8,9,10,11,12};

	for(auto i=0; i<11; ++i)
		check_prime(arr[i]);

	for(auto i=0; i<11; ++i)
		efficient_prime(arr[i]);
}


