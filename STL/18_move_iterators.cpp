
#include <iostream>
#include <vector>
#include <string>
#include <list>

template <typename T>
void printAllElements(const T& coll, const std::string &str)
{
	std::cout<<str;
	for(auto const& p : coll)
		std::cout<<" "<<p;
	std::cout<<std::endl;
	return;
}

void check_move_iterator_adapter(void)
{
	std::list<std::string> lst;

	for(int i = 1; i<=10; ++i)
		lst.push_back("abc");


	//normal way
	std::vector<std::string> coll1(lst.begin(), lst.end());
	printAllElements(coll1, "vector - ");

	//using move iterator
	std::vector<std::string> coll2(std::make_move_iterator(lst.begin()),
									std::make_move_iterator(lst.end()));
	printAllElements(coll2, "move - ");

	std::cout<<std::endl;

	return;
}