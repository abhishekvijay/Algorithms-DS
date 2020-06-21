
#include <iostream>
#include <list>

template <typename T>
void printListElements(const T& coll)
{
	for(const auto& c : coll) {
		std::cout<<" "<<c;
	}
	std::cout<<std::endl;
	return;
}

void check_list()
{
	std::list<char> lst;

	//insert elements
	for(auto i = 'a'; i <= 'z'; ++i)
		lst.push_back(i);

	//print elements
	for(const auto& l : lst)
		std::cout<<" "<<l;
	std::cout<<std::endl;

	//template way
	printListElements(lst);

	//const-iterator - read only mode
	std::list<char>::const_iterator citr;
	for(citr = lst.begin(); citr != lst.end(); ++citr)
		std::cout<<" "<<*citr;
	std::cout<<std::endl;

	//iterator - read/write mode
	std::list<char>::iterator itr;
	for(itr = lst.begin(); itr != lst.end(); ++itr)
		std::cout<<" "<<*itr;
	std::cout<<std::endl;

	//collection way
	while (!lst.empty()) {
		std::cout<<" "<<lst.front();
		lst.pop_front();
	}
	std::cout<<std::endl;

	//print size
	std::cout<<"size - "<<lst.size()<<std::endl;

	return;
}
