

#include <iostream>
#include <deque>

template <typename T>
void printElements(const T& coll)
{  //const reference is used to avoid copy
	for(const auto& elem : coll) {
		std::cout<<" ,"<<elem;
	}
}

void check_deque()
{
	std::deque<char> deq;

	//insert elements
	for(auto p = 'a'; p <= 'z'; ++p)
		deq.push_front(p); //push_back can also be used

	//get size of deque
	std::cout<<"size - "<<deq.size()<<std::endl;

	//print elements
	for(const auto& d : deq)
		std::cout<<" "<<d;
	std::cout<<std::endl;

	//another way to print
	while (!deq.empty()) {
		std::cout<<" "<<deq.front();
		deq.pop_front();
	}
	std::cout<<std::endl;

	//insert via push_back
	for(auto p = 'a'; p <= 'z'; ++p)
		deq.push_back(p);

	//template way
	printElements(deq);
	std::cout<<std::endl;

	//const-iterator
	std::deque<char>::const_iterator citer;
	for(citer = deq.begin(); citer != deq.end(); ++citer)
		std::cout<<" "<<*citer;
	std::cout<<std::endl;

	//iterator
	std::deque<char>::iterator iter;
	for(iter = deq.begin(); iter != deq.end(); ++iter)
		std::cout<<" "<<*iter;
	std::cout<<std::endl;

	return;
}