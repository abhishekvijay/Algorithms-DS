
#include <iostream>
#include <array>

template <typename T>
void printArrayElements(const T& coll)
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
	for(const auto& a : arr)
		std::cout <<" "<<a<<std::endl;

	//template way
	printArrayElements(arr);	

	//const-iterator - read only mode
	std::array<int, 10>::const_iterator citr;
	for(citr = arr.begin(); citr < arr.end(); ++citr)
		std::cout<<" "<<*citr;
	std::cout<<std::endl;

	//iterator - read/write mode
	std::array<int, 10>::iterator itr;
	for(itr = arr.begin(); itr < arr.end(); ++itr)
		std::cout<<" "<<*itr;
	std::cout<<std::endl;

	//get size
	std::cout<<"size -"<<arr.size()<<std::endl;

	return;
}