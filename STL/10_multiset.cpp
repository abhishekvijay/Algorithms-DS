
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

	//const-iterator - read only mode
	std::multiset<std::string>::const_iterator citr;
	for(citr = ms.begin(); citr != ms.end(); ++citr)
		std::cout<<" "<<*citr;
	std::cout<<std::endl;

	//iterator - read/write mode
	std::multiset<std::string>::iterator itr;
	for(itr = ms.begin(); itr != ms.end(); ++itr)
		std::cout<<" "<<*itr;
	std::cout<<std::endl;

	//size
	std::cout<<"size - "<<ms.size()<<std::endl;	

	return;
}