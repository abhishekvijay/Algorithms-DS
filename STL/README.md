
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]


C++ STL Cheatsheet 
===================

Contents
---------
**Utilities:** **[`Pairs`](#pairs)__,__[`Tuples`](#tuples)__,__[`Smart Pointers`](#smartpointers)__,__[`Traits`](#traits)__,__[`Auxiliary Functions`](#auxiliary)**

**The Library:** **[`Containers`](#containers)__,__[`Iterators`](#iterators)__,__[`Algorithms`](#algorithm)__,__[`Iterator Adapters`](#adapters)__,__[`Lambdas`](#lambdas)__,__[`Functors`](#functors)__,__[`Binders`](#binders)**

**STL Containers:** **[`Arrays`](#arrays)__,__[`Vectors`](#vectors)__,__[`Deques`](#deques)__,__[`Lists`](#lists)__,__[`Forward Lists`](#forward_lists)__,__[`Sets & Multisets`](#sets_and_multisets)__,__[`Maps & Multimaps`](#maps_and_multimaps)__,__[`Unordered_Containers`](#unordered_containers)**

**STL Iterators:**

**STL Function Objects:**

**STL Algorithms:**

**Special Containers:**

**Strings:**

**Regular Expressions:**

**Input/Output:**

**Internationalization:**

**Numerics:**

**Concurrency:**

**Allocators:**

**CPP-Internals:**

-------------------------------------------------------------------------------------------------------------------------------------------

ARRAYS
-------------
##### _/* header */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp
#include <array>
```
##### _/* initialization */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp
std::array<int, 6> arr1 = {};						/* all elements default initialized with 0 */
std::array<int, 6> arr2 = {1,2,3,4,5,6};				/* array initialized with initializer list */
std::array<int, 6> arr3 = {1};						/* 1st element is 1, rest all are 0 */
std::array<int, 6> arr4(arr2);						/* copy constructor */
std::array<int, 6> arr5  = arr2;					/* copy constructor */
std::array<int, 6> arr6(std::move(arr2));				/* move constructor */
std::array<int, 6> arr7 = std::move(arr2);				/* move constructor */
```
###### _/* size */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp
std::array<int, 6> arr8 = {3,6,9,12,15,18};
std::cout<<"empty - "<<arr8.empty()<<std::endl;				/* empty */
std::cout<<"size - "<<arr8.size()<<std::endl;				/* size */
std::cout<<"max size - "<<arr8.max_size()<<std::endl;			/* max_size */
```
###### _/* assignment */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp
std::array<int, 6> arr9;
arr9.fill(10);								/* assigns value to each element in array */	
arr9.swap(arr8);							/* using swap */
std::swap(arr8, arr9);							/* alternative way - swap */	
```
###### _/* element-access */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp
std::cout<<"element at pos 5 = "<<arr8[5]<<std::endl;			/* direct access */
std::cout<<"element at pos 5 = "<<arr8.at(4)<<std::endl;		/* direct access */
std::cout<<"front element = "<<arr8.front()<<std::endl;			/* access front element */
std::cout<<"back element = "<<arr8.back()<<std::endl;			/* access last element */
```
###### _/* iterators */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp
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
```
###### _/* tuple interface */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp
typedef std::array<std::string, 6> CustomString;

CustomString str = {"Delhi", "London", "NewYork", "Greece", "Italy"};

std::cout<<"tuple size - "<<std::tuple_size<CustomString>::value<<std::endl;
std::cout<<"tuple element - "<<std::tuple_element<2, CustomString>::type()<<std::endl;
std::cout<<"get element - "<<std::get<2>(str)<<std::endl;
```
###### _/* print array elements */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp
for(const auto& a : arr8)						/* range based loops */
	std::cout <<" "<<a<<std::endl;
										
/* generic function using templates */									
template <typename T>
void printArrayElements(const T& coll)					/* template method */
{
	for(const auto& t : coll) {
		std::cout<<" "<<t;
	}
	std::cout<<std::endl;
}
```
###### _/* notes */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
-------------------------------------------------------------------------------------------------------------------------------------------


VECTORS
--------
##### _/* initialization */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* size */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* assignment */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* element-access */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* iterators */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* tuple interface */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* print array elements */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* notes */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
-------------------------------------------------------------------------------------------------------------------------------------------


DEQUES 
-------
##### _/* initialization */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* size */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* assignment */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* element-access */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* iterators */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* tuple interface */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* print array elements */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* notes */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
-------------------------------------------------------------------------------------------------------------------------------------------


LISTS 
-----
##### _/* initialization */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* size */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* assignment */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* element-access */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* iterators */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* tuple interface */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* print array elements */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* notes */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
-------------------------------------------------------------------------------------------------------------------------------------------


FORWARD_LISTS 
-------------
##### _/* initialization */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* size */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* assignment */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* element-access */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* iterators */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* tuple interface */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* print array elements */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* notes */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
-------------------------------------------------------------------------------------------------------------------------------------------


SETS_and_MULTISETS 
-----------------
##### _/* initialization */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* size */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* assignment */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* element-access */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* iterators */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* tuple interface */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* print array elements */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* notes */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
-------------------------------------------------------------------------------------------------------------------------------------------


MAPS_and_MULTIMAPS
-----------------
##### _/* initialization */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* size */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* assignment */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* element-access */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* iterators */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* tuple interface */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* print array elements */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* notes */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
-------------------------------------------------------------------------------------------------------------------------------------------


UNORDERED_CONTAINERS
---------------------
##### _/* initialization */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* size */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* assignment */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* element-access */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* iterators */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* tuple interface */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* print array elements */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
###### _/* notes */_ [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
```cpp

```
-------------------------------------------------------------------------------------------------------------------------------------------


## ACKNOWLEDGEMENTS [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
* [Nicolai M. Josuttis](http://www.josuttis.com/)
* [StackOverflow](https://stackoverflow.com/)

[contributors-shield]: https://img.shields.io/github/contributors/abhishekvijay/Algorithms-DS.svg?style=flat-square
[contributors-url]: https://github.com/abhishekvijay/Algorithms-DS/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/abhishekvijay/Algorithms-DS.svg?style=flat-square
[forks-url]: https://github.com/abhishekvijay/Algorithms-DS/network/members
[stars-shield]: https://img.shields.io/github/stars/abhishekvijay/Algorithms-DS.svg?style=flat-square
[stars-url]: https://github.com/abhishekvijay/Algorithms-DS/stargazers
[issues-shield]: https://img.shields.io/github/issues/abhishekvijay/Algorithms-DS.svg?style=flat-square
[issues-url]: https://github.com/abhishekvijay/Algorithms-DS/issues


## BOOKS [<img align="right" width="20" height="20" src="./Resources/topdouble.png" title="Go to Contents">](#Contents)
1. Code Complete
2. Effective C++
3. More Effective C++
4. Modern C++
5. Exceptional C++
6. More Exceptional C++
7. Modern C++ Design
8. Modern C++ CookBook
9. Effective STL
10. The Boost C++ Libraries
11. C++ Template Metaprogramming
12. C++ STL with CPP11
