
#include <iostream>
#include <array>

template <typename T>
void printElements(const T& coll)
{
	for(const auto& t : coll) {
		std::cout<<" "<<t;
	}
	std::cout<<std::endl;
}

void check_array()
{
	std::array<int, 10> arr = {1,2,3,4,5,6}; //initializer list

	//print elements
	for(auto a : arr)
		std::cout <<" "<<a<<std::endl;

	//template way
	printElements(arr);

	//get size
	std::cout<<"size -"<<arr.size()<<std::endl;

	std::cout<<std::endl;

	return;
}