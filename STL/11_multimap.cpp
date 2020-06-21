
#include <iostream>
#include <string>
#include <map>


template <typename T>
void printMapElements(const T& coll) {
	for(const auto& p : coll)
		std::cout<<"["<<p.first<<","<<p.second<<"]"<<std::endl;
	std::cout<<std::endl;
	return;
}

void check_multimap(void)
{
	std::multimap<int, std::string> mm;

	//insert
	std::pair<int, std::string> p1 (100000, "MNO");
	std::pair<int, std::string> p2 (10000, "JKL");
	std::pair<int, std::string> p3 (1000, "GHI");
	std::pair<int, std::string> p4 (100, "DEF");
	std::pair<int, std::string> p5 (1, "ABC");
	std::pair<int, std::string> p6 (100, "DEF");
	std::pair<int, std::string> p7 (1000, "GHI");
	std::pair<int, std::string> p8 (10000, "JKL");
	std::pair<int, std::string> p9 (100000, "MNO");

	mm.insert(p1); mm.insert(p2);
	mm.insert(p3); mm.insert(p4);
	mm.insert(p5); mm.insert(p6);
	mm.insert(p7); mm.insert(p8);
	mm.insert(p9);	

	//print
	for (const auto& p : mm)
		std::cout<<"["<<p.first<<","<<p.second<<"]"<<std::endl;

	std::cout<<std::endl;

	//template way
	printMapElements(mm);

	//const-iterator - read only mode
	std::multimap<int, std::string>::const_iterator citr;
	for(citr = mm.begin(); citr != mm.end(); ++citr)
		std::cout<<"["<<citr->first<<","<<citr->second<<"]"<<std::endl;
	std::cout<<std::endl;

	//iterator - read/write mode
	std::multimap<int, std::string>::iterator itr;
	for(itr = mm.begin(); itr != mm.end(); ++itr)
		std::cout<<"["<<itr->first<<","<<itr->second<<"]"<<std::endl;
	std::cout<<std::endl;

	//size
	std::cout<<"size - "<<mm.size()<<std::endl;

	std::cout<<std::endl;

	return;
}