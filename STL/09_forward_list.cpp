

#include <iostream>
#include <forward_list>

template <typename T>
void printFLElements(const T& coll)
{
	for(const auto& p : coll) {
		std::cout<<" "<<p;
	}
	std::cout<<std::endl;
	return;
}

void check_forward_list()
{
	std::forward_list<char> fl;

	//insert element - push_back not supported due to performance
	for(auto p = 'a'; p <= 'z' ; ++p)
		fl.push_front(p);

	//print elements
	for(const auto& l : fl)
		std::cout<<" "<<l;
	std::cout<<std::endl;

	//template way
	printFLElements(fl);

	//const-iterator - read only mode
	std::forward_list<char>::const_iterator citr;
	for(citr = fl.begin(); citr != fl.end(); ++citr)
		std::cout<<" "<<*citr;
	std::cout<<std::endl;

	//iterator - read/write mode
	std::forward_list<char>::iterator itr;
	for(itr = fl.begin(); itr != fl.end(); ++itr)
		std::cout<<" "<<*itr;
	std::cout<<std::endl;

	//collection way
	while (!fl.empty()) {
		std::cout<<" "<<fl.front();
		fl.pop_front();
	}
	std::cout<<std::endl;

	return;
}
