
#include <iostream>
#include <vector>
#include <string>

void check_reverse_iterator_adapter(void)
{
	std::vector<int> coll;

	for(int i = 1; i <= 10; ++i)
		coll.push_back(i);

	std::copy(coll.crbegin(), coll.crend(), std::ostream_iterator<int>(std::cout, "\n"));

	std::cout<<std::endl;

	return;
}