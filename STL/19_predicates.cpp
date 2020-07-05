
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>

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
template <typename T>
void printPrElements(const T& coll)
{
	for (auto const& p : coll)
		std::cout<<"["<<std::get<0>(p)<<","<<std::get<1>(p)<<"]"<<std::endl;
	return;
}

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
	return true;
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

typedef std::pair<int, std::string> paer;

bool sortCriteria(const paer& T1, const paer& T2)
{	
	int num1 = std::get<0>(T1);
	int num2 = std::get<0>(T2);

	if (num1 < num2) 
		return true;
	else
		return false;
}

void binary_predicates()
{
	std::unordered_map<int, std::string> coll;

	paer p1(100000, "MNO");
	paer p2(10000, "JKL");
	paer p3(10, "ABC");
	paer p4(100, "DEF");
	paer p5(1000, "GHI");

	coll.insert(p1); coll.insert(p2);
	coll.insert(p3); coll.insert(p4);
	coll.insert(p5);

	//correct sorting criteria
	//std::sort(coll.begin(), coll.end(), sortCriteria);

	printPrElements(coll);

	std::cout<<std::endl;

	return;
}

void check_predicates(void)
{
	unary_predicates();

	binary_predicates();

	return;
}