
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

template <typename T>
void printSorted(const T& coll)
{
	for(auto const& p : coll)
		std::cout<<" "<<p;
	std::cout<<std::endl;
	return;
}

void print(int val)
{
	std::cout<<val<<std::endl;
	return;
}

int csquare(int val)
{
	return (val*val);
}

/*
remove() algorithm can only be applied to sequence containters. 
Associative containers have values in specific order, applying remove() will destroy that order.
Hence in case of associative containers, it is best to use their own member function - erase().
*/

void check_remove_element_algorithm()
{
	std::list<int> coll;

	std::cout<<"================ remove algo ================"<<std::endl;

	//insert 1~10 & 10~1
	for(int i=1; i<=10; ++i)
	{
		coll.push_back(i);
		coll.push_front(i);
	}

	//print
	std::cout<<"pre - ";
	std::copy(coll.begin(), coll.end(), std::ostream_iterator<int>(std::cout," "));

	//remove - this provides new end after removing elements from collection
	std::list<int>::iterator end = std::remove(coll.begin(), coll.end(), 5);
	std::cout<<std::endl;

	//print all elements in collection
	std::cout<<"post - ";
	std::copy(coll.begin(), end, std::ostream_iterator<int>(std::cout," "));
	std::cout<<std::endl;

	//print no. of removed elements
	std::cout<<"no. of removed elements - "<<std::distance(end, coll.end())<<std::endl;

	//remove removed elements, after erasing elements, coll.end() == end
	coll.erase(end, coll.end());

	//print modified collection
	std::copy(coll.begin(), coll.end(), std::ostream_iterator<int>(std::cout, " "));

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

	//find element when order is not known
	//we will find either of one of them first
	//then from first element's position we will check for other element
	auto posn = std::find_if(vec.begin(), vec.end(), [](const int& i) { return i==55 || i==66; });
	if (posn == vec.end())
	{
		std::cout<<"both elements not available"<<std::endl;
	}
	else if (*posn == 55)
	{
		auto start = posn;
		auto pos66 = std::find(++start, vec.end(), 66);
	}
	else if (*posn == 66)
	{
		auto start = posn;
		auto pos55 = std::find(++start, vec.end(), 55);
	}

	//algorithm remove() & its correct usage
	check_remove_element_algorithm();

	std::cout<<"##########################"<<std::endl;

	//check for_each(), transform()
	std::vector<int> coll, coll2;

	for(int j = 1; j <= 10; ++j)
		coll.push_back(j);

	std::for_each(coll.begin(), coll.end(), print);

	std::transform(coll.begin(), coll.end(), std::back_inserter(coll2),csquare);

	printSorted(coll2);

	std::cout<<std::endl;
	return;
}