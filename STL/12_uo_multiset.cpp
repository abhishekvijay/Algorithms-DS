
#include <iostream>
#include <unordered_set>
#include <string>

template <typename T>
void printUOMSElements(const T& coll)
{
	for(const auto& p : coll)
		std::cout<<" "<<p;
	std::cout<<std::endl;
	return;
}

void check_uo_multiset(void)
{
	std::unordered_multiset<std::string> ms;

	//insert
	ms.insert("JKL");
	ms.insert("DEF");
	ms.insert("ABC");
	ms.insert("MNO");
	ms.insert("DEF");
	ms.insert("GHI");
	ms.insert("JKL");
	ms.insert("MNO");

	//size
	std::cout<<"size -"<<ms.size()<<std::endl;

	//print
	for(const auto& p : ms)
		std::cout<<" "<<p;
	std::cout<<std::endl;

	//template way
	printUOMSElements(ms);

	//const-iterator - read only mode
	std::unordered_multiset<std::string>::const_iterator citr;
	for(citr = ms.begin(); citr != ms.end(); ++citr)
		std::cout<<" "<<*citr;
	std::cout<<std::endl;

	//iterator - read/write mode
	std::unordered_multiset<std::string>::iterator itr;
	for(itr = ms.begin(); itr != ms.end(); ++itr)
		std::cout<<" "<<*itr;
	std::cout<<std::endl;	
	
	return;
}