
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

/*
One application of these iterators is to let algorithms move instead of copy elements from one range
into another. However, note that in general, the move() algorithm also does that.

In general, using a move iterator in algorithms only makes sense when the algorithm transfers
elements of a source range to a destination range. In addition, you have to ensure that each element
is accessed only once. Otherwise, the contents would be moved more than once, which would result
in undefined behavior.

The only iterator category that guarantees that elements are read or processed only
once is the input iterator categor. Thus, using move iterators usually
makes sense only when an algorithm has a source where the input iterator category is required and
a destination that uses the output iterator category. The only exception is for_each(), which can
be used to process the moved elements of the passed range (for example, to move them into a new
container).
*/

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