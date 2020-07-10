
#include <iostream>
#include <array>
#include <string>

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
/* initialization */
	std::array<int, 6> arr1 = {};						/* all elements default initialized with 0 */
	std::array<int, 6> arr2 = {1,2,3,4,5,6};				/* array initialized with initializer list */
	std::array<int, 6> arr3 = {1};						/* 1st element is 1, rest all are 0 */
	std::array<int, 6> arr4(arr2);						/* copy constructor */
	std::array<int, 6> arr5  = arr2;					/* copy constructor */
	std::array<int, 6> arr6(std::move(arr2));				/* move constructor */
	std::array<int, 6> arr7 = std::move(arr2);				/* move constructor */

/* size */
	std::array<int, 6> arr8 = {3,6,9,12,15,18};
	std::cout<<"empty - "<<arr8.empty()<<std::endl;				/* empty */
	std::cout<<"size - "<<arr8.size()<<std::endl;				/* size */
	std::cout<<"max size - "<<arr8.max_size()<<std::endl;			/* max_size */

/* assignment */
	std::array<int, 6> arr9;
	arr9.fill(10);								/* assigns value to each element in array */	
	arr9.swap(arr8);							/* using swap */
	std::swap(arr8, arr9);							/* alternative way - swap */	

/* element-access */
	std::cout<<"element at pos 5 = "<<arr8[5]<<std::endl;			/* direct access */
	std::cout<<"element at pos 5 = "<<arr8.at(4)<<std::endl;		/* direct access */
	std::cout<<"front element = "<<arr8.front()<<std::endl;			/* access front element */
	std::cout<<"back element = "<<arr8.back()<<std::endl;			/* access last element */

/* iterators */
	/* normal iterator - read/write mode */
	std::array<int, 6>::iterator itr;					/* normal iterator */
	std::cout<<"itr - ";
	for(itr = arr8.begin(); itr != arr8.end(); ++itr)
		std::cout<<" "<<*itr;
	std::cout<<std::endl;

	/* const-iterator - read only mode */
	std::array<int, 6>::const_iterator citr;				/* constant iterator */
	std::cout<<"citr - ";
	for(citr = arr8.cbegin(); citr != arr8.cend(); ++citr)
		std::cout<<" "<<*citr;
	std::cout<<std::endl;

	/* reverse iterator */
	std::array<int, 6>::reverse_iterator ritr;				/* reverse iterator */
	std::cout<<"ritr - ";
	for(ritr = arr8.rbegin(); ritr != arr8.rend(); ++ritr)
		std::cout<<" "<<*ritr;
	std::cout<<std::endl;

	/* const-reverse iterator */
	std::array<int, 6>::const_reverse_iterator critr;			/* constant reverse iterator */
	std::cout<<"citr - ";
	for(critr = arr8.crbegin(); critr != arr8.crend(); --critr)
		std::cout<<" "<<*critr;
	std::cout<<std::endl;

/* tuple interface */
	typedef std::array<std::string, 6> CustomString;

	CustomString str = {"Delhi", "London", "NewYork", "Greece", "Italy"};

	std::cout<<"tuple size - "<<std::tuple_size<CustomString>::value<<std::endl;
	std::cout<<"tuple element - "<<std::tuple_element<2, CustomString>::type()<<std::endl;
	std::cout<<"get element - "<<std::get<2>(str)<<std::endl;

//print array elements	
	for(const auto& a : arr8)						/* range based loops */
		std::cout <<" "<<a<<std::endl;

	printArrayElements(arr8);						/* generic templates */

	return;
}
