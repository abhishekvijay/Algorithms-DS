
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>

template <typename T>
void printUOMMElements(const T& coll)
{
	for(const auto& p : coll)
		std::cout<<"["<<p.first<<","<<p.second<<"]"<<std::endl;
	std::cout<<std::endl;
	return;
}

void check_uo_multimap(void)
{
	std::unordered_multimap<int, std::string> um;

	//create pairs	
	std::pair<int, std::string> p2(1000, "DEF");
	std::pair<int, std::string> p1(10000, "ABC");	
	std::pair<int, std::string> p4(100, "JKL");
	std::pair<int, std::string> p3(1000, "GHI");
	std::pair<int, std::string> p5(100, "MNO");
	std::pair<int, std::string> p6(10, "PQR");

	//insert
	um.insert(p1); um.insert(p2);
	um.insert(p3); um.insert(p4);
	um.insert(p5); um.insert(p6);

	//size
	std::cout<<"size -"<<um.size()<<std::endl;	

	//print
	for(const auto&  p : um)
		std::cout<<"["<<p.first<<","<<p.second<<"]"<<std::endl;

	std::cout<<std::endl;

	//template way
	printUOMMElements(um);

	//const-iterator - read only mode
	std::unordered_multimap<int, std::string>::const_iterator citr;
	for(citr = um.begin(); citr != um.end(); ++citr)
		std::cout<<"["<<citr->first<<","<<citr->second<<"]"<<std::endl;
	std::cout<<std::endl;

	//iterator - read/write mode
	std::unordered_multimap<int, std::string>::iterator itr;
	for(itr = um.begin(); itr != um.end(); ++itr)
		std::cout<<"["<<itr->first<<","<<itr->second<<"]"<<std::endl;
	std::cout<<std::endl;	

	std::cout<<std::endl;
	return;
}