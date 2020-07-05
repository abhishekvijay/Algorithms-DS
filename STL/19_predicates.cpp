
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/*
A predicate is a special kind of auxiliary function. Predicates return a Boolean value and are often
used to specify a sorting or a search criterion. Depending on their purpose, predicates are unary or
binary.

Not every unary or binary function that returns a Boolean value is a valid predicate. In addition,
the STL requires that predicates be stateless, meaning that they should always yield the same result
for the same value. This rules out functions that modify their internal state when they are called.

Unary predicates check a specific property of a single argument. A typical example is a function that
is used as a search criterion to find the first prime number

Binary predicates typically compare a specific property of two arguments. For example, to sort
elements according to your own criterion, you could provide it as a simple predicate function.
*/

bool isPrime(int num)
{
	(num < 0) ? (num *= -1) : num;

	if (num <= 1)		
		return false;

	if (num <= 3)	
		return true;

	if ((num % 2 == 0) || (num % 3 == 0))		
		return false;

	for(auto i = 5; i*i<num; i+=6) {
		if ((num % i == 0) || (num % (i+2) == 0))			
			return false;		
	}
}

void unary_predicates()
{
	std::list<int> coll;

	for(int i = 18; i<20; ++i)
		coll.push_back(i);

	auto pos = std::find_if(coll.begin(), coll.end(), isPrime);

	if (pos == coll.end())
		std::cout<<"no prime no. available"<<std::endl;
	else
		std::cout<<" "<<*pos<<std::endl;

	std::cout<<std::endl;

	return;
}

void binary_predicates()
{
	return;
}

void check_predicates(void)
{
	unary_predicates();

	binary_predicates();

	return;
}