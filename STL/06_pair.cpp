
#include <iostream>
#include <utility>
#include <tuple>

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

class Foo {
public:
	Foo(std::tuple<int, double>) {
		std::cout<<"Foo::Foo(tuple)"<<std::endl;
	}
	template <typename T1, typename T2>
	Foo(T1 args1, T2 args2) {
		std::cout<<"Foo::Foo(args)"<<std::endl;
	}
};

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

	//copy-constructor
	paer p4(p1);
	std::cout<<"["<<std::get<0>(p4)<<","<<std::get<1>(p4)<<"]"<<std::endl;	
	paer p5 = p2;
	std::cout<<"["<<std::get<0>(p5)<<","<<std::get<1>(p5)<<"]"<<std::endl;

	//(==), (!=), (<=), (>=), (>), (<) - are also supported

	//piecewise-construct
	std::tuple<int, double> t(20, 40.60);
	std::pair<int, Foo> p6(32, t);
	std::pair<int, Foo> p7(std::piecewise_construct, std::make_tuple(64), t);

	//make pair
	paer p3 = std::make_pair(20, 30.60);
	std::cout<<"["<<std::get<0>(p3)<<","<<std::get<1>(p3)<<"]"<<std::endl;
	auto p8 = std::make_pair(12.12, 13.13);
	std::cout<<"["<<std::get<0>(p8)<<","<<std::get<1>(p8)<<"]"<<std::endl;

	// ref-semantics on make_pair
	int i = 2;
	auto p9 = std::make_pair(std::ref(i), std::ref(i));
	p9.first += 1;
	p9.second += 1;
	std::cout<<"value of i = "<<i<<std::endl;

	//move-semantics on make_pair
	std::string s1("abc");
	std::string s2("xyz");
	auto p10 = std::make_pair(std::move(s1), std::move(s2));
	//std::cout<<"["<<p10.first<<","<<p10.second<<"]"<<std::endl;

	std::cout<<std::endl;

	return;
}
