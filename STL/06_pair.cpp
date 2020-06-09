
#include <iostream>
#include <utility>
#include <tuple>

/*
namespace std {
	template<typename T1, typename T2>
	struct pair 
	{
		public:
			T1 first;
			T2 second;
		
		//constructors
		pair(const T1& x, const T2& y);
		template<typename U, typename V> pair(U&& x, V&& y);
		template <typename... Args1, typename... Args2>
		pair(piecewise_construct_t, tuple<Args1...> first_args, tuple<Args2...> second_args);

		//print values
		template<typename T1, typename T2>
		std::ostream& operator << (std::ostream& strm, const std::pair<T1,T2>& p)
		{
			return strm << "[" << p.first << "," << p.second << "]";
		}

		// create value pair only by providing the values - reference semantics
		template <template T1, template T2> 
		pair<T1,T2> make_pair (const T1& x, const T2& y) 
		{
			return pair<T1,T2>(x,y);
		}

		// create value pair only by providing the values - move semantics
		template <template T1, template T2>
		pair<V1,V2> make_pair (T1&& x, T2&& y);

		template <typename T1, typename T2>
		bool operator== (const pair<T1,T2>& x, const pair<T1,T2>& y) 
		{
			return x.first == y.first && x.second == y.second;
		}

		//In a comparison of pairs, the first value has higher priority. 
		//Thus, if the first values of two pairs differ, the result of their 
		//comparison is used as the result of the overall comparison of the pairs. 
		//If the members first are equal, the comparison of the members second yields the overall result

		template <typename T1, typename T2>
		bool operator< (const pair<T1,T2>& x, const pair<T1,T2>& y) 
		{
			return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
		}
	};
}
*/

//Usability of pair - maps, multimaps, unordered maps, unordered multimaps

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
