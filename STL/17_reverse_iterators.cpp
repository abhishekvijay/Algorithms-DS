
#include <iostream>
#include <vector>
#include <string>

/*
Reverse iterators let algorithms operate backward by switching the call of an increment operator
internally into a call of the decrement operator, and vice versa. All containers with bidirectional
iterators or random-access iterators (all sequence containers except forward_list and all associative
containers) can create reverse iterators via their member functions rbegin() and rend().
*/

void check_reverse_iterator_adapter(void)
{
	std::vector<int> coll;

	for(int i = 1; i <= 10; ++i)
		coll.push_back(i);

	std::copy(coll.crbegin(), coll.crend(), std::ostream_iterator<int>(std::cout, "\n"));

	std::cout<<std::endl;

	return;
}