
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
	for(auto l : lst)
		std::cout<<" "<<l;

	std::cout<<std::endl;

	//template way
	printListElements(lst);

	std::cout<<std::endl;

	//collection way
	while (!lst.empty())
	{
		std::cout<<" "<<lst.front();
		lst.pop_front();
	}

	std::cout<<std::endl;

	//print size
	std::cout<<"size - "<<lst.size()<<std::endl;

	return;
}
