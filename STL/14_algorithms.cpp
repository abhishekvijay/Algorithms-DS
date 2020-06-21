
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <typename T>
void printSorted(const T& coll)
{
	for(auto const& p : coll)
		std::cout<<" "<<p;
	std::cout<<std::endl;
	return;
}

void check_algorithm(void)
{
	std::vector<int> vec;
	
	//insert
	for(register int i = 10; i>=0; --i)
		vec.push_back(i*11);

	//print
	std::vector<int>::const_iterator itr;
	for(itr = vec.begin(); itr != vec.end(); ++itr)
		std::cout<<" "<<*itr;
	std::cout<<std::endl;

	//min,max - itertor objects are returned
	auto min = std::min_element(vec.begin(), vec.end());
	auto max = std::max_element(vec.begin(), vec.end());
	std::cout<<"min-max element -["<<*min<<","<<*max<<"]"<<std::endl;	

	//sort
	std::sort(vec.begin(), vec.end());
	printSorted(vec);

	//find - 8
	auto find8 = std::find(vec.begin(), vec.end(), 88);
	std::cout<<"elem - "<<*find8<<std::endl;

	//reverse
	std::reverse(vec.begin(), vec.end());
	printSorted(vec);

	//minmax together as pair
	auto elm = std::minmax_element(vec.begin(), vec.end());
	std::cout<<"["<<*elm.first<<","<<*elm.second<<"]"<<std::endl;

	std::cout<<std::endl;
	return;
}