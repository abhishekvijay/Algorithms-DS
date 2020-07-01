

#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include <algorithm>

void check_stream_iterator_adapter(void)
{
	std::vector<std::string> coll;

	//reading input from std::cin
	std::copy(std::istream_iterator<std::string>(std::cin),
				std::istream_iterator<std::string>(),
				std::back_inserter(coll));

	//sorting elements
	std::sort(coll.begin(), coll.end());

	//copy to std::cout
	std::unique_copy(coll.begin(), coll.end(), 
				std::ostream_iterator<std::string>(std::cout, "\n"));
	
	std::cout<<std::endl;
	return;
}