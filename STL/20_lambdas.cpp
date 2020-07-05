

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>

template < typename T>
void printLambdaElements(const T& coll, const std::string& str)
{
	std::cout<<str;
	for(auto const& p : coll)
		std::cout<<" "<<p;
	std::cout<<std::endl;
	return;
}

/*
if [=] is used then it means the input arguments are read only.
if [&] is used then it means the input arguments can be modified.

lambdas have no default constructor & assignemnt operator.

Another problem of lambdas is that they can’t have an internal state held over multiple calls of a
lambda. If you need such a state, you have declare an object or variable in the outer scope and pass
it by-reference with a capture into the lambda. 

In contrast, function objects allow you to encapsulate an internal state. Nevertheless, you can also
use lambdas to specify a hash function and/or equivalence criterion of unordered containers.
*/
void check_lambdas(void)
{
	std::list<int> coll;

	for(int i = 1; i<=10; ++i)
		coll.push_back(i);

	printLambdaElements(coll, "before transform - ");

	//used during transform()
	std::transform(coll.begin(), coll.end(), coll.begin(),
										[](int val) {
											return val*val;
										});

	printLambdaElements(coll, "after transform - ");

	//used during find()
	auto pos = std::find_if(coll.begin(), coll.end(), 
										[=](int val) {														
											return (val > 30 && val < 50);
										});
	std::cout<<" "<<*pos<<std::endl;


	return;
}