

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
	for(auto l : fl)
		std::cout<<" "<<l;

	std::cout<<std::endl;

	//template way
	printFLElements(fl);

	std::cout<<std::endl;

	//collection way
	while (!fl.empty())
	{
		std::cout<<" "<<fl.front();
		fl.pop_front();
	}

	std::cout<<std::endl;

	return;
}
