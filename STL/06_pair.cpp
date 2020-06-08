
#include <iostream>
#include <utility>

/*
namespace std {
	template<typename T1, typename T2>
	struct pair {
		T1 first;
		T2 second;
	};
}
*/

typedef std::pair<int, double> paer;

void check_pair(void)
{
	//initialize
	paer p1;
	paer p2(10, 20.40);

	std::cout<<"["<<p1.first<<","<<p1.second<<"]"<<std::endl;
	std::cout<<"["<<p2.first<<","<<p2.second<<"]"<<std::endl;

	//swap
	p1.swap(p2);
	std::cout<<"after swap - 1"<<std::endl;
	std::cout<<"["<<p1.first<<","<<p1.second<<"]"<<std::endl;
	std::cout<<"["<<p2.first<<","<<p2.second<<"]"<<std::endl;

	std::swap(p1, p2);
	std::cout<<"after swap - 2"<<std::endl;
	std::cout<<"["<<p1.first<<","<<p1.second<<"]"<<std::endl;
	std::cout<<"["<<p2.first<<","<<p2.second<<"]"<<std::endl;

	//make pair
	paer p3 = std::make_pair(20, 30.60);
	std::cout<<"["<<std::get<0>(p3)<<","<<std::get<1>(p3)<<"]"<<std::endl;

	//copy-constructor
	paer p4(p3);
	std::cout<<"["<<std::get<0>(p4)<<","<<std::get<1>(p4)<<"]"<<std::endl;	
	paer p5 = p2;
	std::cout<<"["<<std::get<0>(p5)<<","<<std::get<1>(p5)<<"]"<<std::endl;

	//(==), (!=), (<=), (>=), (>), (<) - are also supported

	std::cout<<std::endl;

	return;
}
