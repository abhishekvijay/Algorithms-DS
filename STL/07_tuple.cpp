
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <tuple>

void check_tuple()
{
	//tuple initialization
	std::tuple<int, int, std::string> t1;  //default init to 0;
	std::tuple<int, int, std::string> t2(10, 20, "hello"); //initialized tuple

	//tuple prints
	std::cout<<"["<<std::get<0>(t2)<<","<<std::get<1>(t2)<<","<<std::get<2>(t2)<<"]"<<std::endl;

	//pair assignment
	std::pair<int, std::string> p(100, "world");
	auto t3 = p;
	auto t4(p);
	std::cout<<"["<<std::get<0>(t3)<<","<<std::get<1>(t3)<<"]"<<std::endl;
	std::cout<<"["<<std::get<0>(t4)<<","<<std::get<1>(t4)<<"]"<<std::endl;

	//copy constructor
	auto t5 = t2;
	std::cout<<"["<<std::get<0>(t5)<<","<<std::get<1>(t5)<<","<<std::get<2>(t5)<<"]"<<std::endl;

	//==, !=, <, >, <=, >=

	//tuple swap
	std::tuple<int, int, std::string> t7;
	t7.swap(t5);
	std::cout<<"["<<std::get<0>(t7)<<","<<std::get<1>(t7)<<","<<std::get<2>(t7)<<"]"<<std::endl;

	std::tuple<int, int, std::string> t8;
	std::swap(t7, t8);
	std::cout<<"["<<std::get<0>(t8)<<","<<std::get<1>(t8)<<","<<std::get<2>(t8)<<"]"<<std::endl;

	//make_tuple & tie
	auto tpl = std::make_tuple(10, 20, 30, 99.88);
	std::cout<<"["<<std::get<0>(tpl)<<","<<std::get<1>(tpl)<<","<<std::get<2>(tpl)<<","<<std::get<3>(tpl)<<"]"<<std::endl;

	std::tuple<int, int, std::string> t9(10,20,"name");

	int a,b; std::string s;
	std::make_tuple(std::ref(a), std::ref(b), std::ref(s)) = t9;
	std::cout<<"t9 = ["<<a<<","<<b<<","<<s<<"]"<<std::endl;

	int c, d; std::string s1;
	std::tie(c,d,s1) = t9;
	std::cout<<"t9 = ["<<c<<","<<d<<","<<s1<<"]"<<std::endl;

	//std::ignore
	int e; std::string s2;
	std::tie(e, std::ignore, s2) = t9;
	std::cout<<"ignore - ["<<e<<","<<s2<<"]"<<std::endl;

	int f;
	std::tie(std::ignore, f, std::ignore) = t9;
	std::cout<<"ignore 2 - "<<f<<std::endl;

	//initializer list -- currently not working
	//std::vector<std::pair<int, double>> v1 {{10,11.22}, {20,21.42}};

	//tuple size
	typedef std::tuple<int, int, int, double> t10;
	std::cout<<"size - "<<std::tuple_size<t10>::value<<std::endl;

	//tuple type - dont know why syntax error on this ?
	//std::cout<<"type - "<<std::tuple_element<3,t10>::type<<std::endl;

	//tuple concatenate
	auto tc = std::tuple_cat(std::make_tuple(10, "hello"), \
							 std::make_tuple(20, "world"));
	std::cout<<"["<<std::get<0>(tc)<<","<<std::get<1>(tc)<<"]" \
		<<","<<"["<<std::get<2>(tc)<<","<<std::get<3>(tc)<<"]"<<std::endl;

	//tuple I/O

	
	std::cout<<std::endl;

	return;
}