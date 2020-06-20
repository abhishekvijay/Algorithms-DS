
#include <iostream>
#include <string>
#include <set>

template <typename T>
void printSetElements(const T& coll)
{
	for(const auto& p : coll) {
		std::cout<<" "<<p;
	}
	std::cout<<std::endl;
}

void check_multiset(void)
{
	std::multiset<std::string> ms;

	//insert more values
	ms.insert("delhi");
	ms.insert("tamilnadu");
	ms.insert("mumbai");
	ms.insert("delhi");
	ms.insert("mumbai");
	ms.insert("ahemadabad");

	//print
	for(const auto& p : ms)
		std::cout<<" "<<p;

	std::cout<<std::endl;

	//template way
	printSetElements(ms);

	//size
	std::cout<<"size - "<<ms.size()<<std::endl;	

	return;
}