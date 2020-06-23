

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <set>

template <typename T>
void printContainerElements(const T& coll, const std::string &str)
{
	std::cout<<str;
	for(auto const& p : coll) {
		std::cout<<" "<<p;
	}
	std::cout<<std::endl;
	return;
}

void check_insert_iterator(void)
{
	std::list<int> coll;

	//insert
	for(int i=1; i<=10; ++i)
		coll.push_back(i);
	printContainerElements(coll, "list - ");

	//copy to vector
	std::vector<int> vec;
	std::copy(coll.cbegin(), coll.cend(), std::back_inserter(vec));
	printContainerElements(vec, "vector - ");

	//copy to deque
	std::deque<int> deq;
	std::copy(coll.cbegin(), coll.cend(), std::front_inserter(deq));
	printContainerElements(deq, "deque - ");

	//copy to set
	std::set<int> st;
	std::copy(coll.cbegin(), coll.cend(), std::inserter(st, st.begin()));
	printContainerElements(st, "set - ");

	std::cout<<std::endl;

	return;
}
