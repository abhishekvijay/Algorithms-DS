

#include <iostream>
#include <vector>
#include <string>

template <typename T>
void printVectorElements(const T& coll)
{
	for (auto const& p : coll)
		std::cout<<" "<<p;
	std::cout<<std::endl;
	return;
}

void check_vector()
{
	std::vector<char> vec;

	//insert 
	for(auto p = 'a'; p <= 'z'; ++p)
		vec.push_back(p);

	std::cout<<"size - "<<vec.size()<<std::endl;

	//print
	for(const auto& v : vec)
		std::cout<<" "<<v;
	std::cout<<std::endl;

	//template way
	printVectorElements(vec);	

	//const-iterator - read only mode
	std::vector<char>::iterator pos;
	for(pos = vec.begin(); pos < vec.end(); ++pos)
		std::cout<<" "<<*pos;
	std::cout<<std::endl;

	//iterator - read/write mode
	std::vector<char>::iterator iter;
	for(iter = vec.begin(); iter < vec.end(); ++iter)
		std::cout<<" "<<*iter;
	std::cout<<std::endl;

	return;
}