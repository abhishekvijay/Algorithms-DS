

#include <iostream>
#include <vector>

void check_vector()
{
	std::vector<char> vec;

	for(auto p = 'a'; p <= 'z'; ++p)
		vec.push_back(p);

	std::cout<<"size - "<<vec.size()<<std::endl;

	for(auto v : vec)
		std::cout<<" "<<v;

	std::cout<<std::endl;

	return;
}