

#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

/* Iteratory types
Output			unidirectional		Ofstream, inserter
Input			unidirectional		Istream
Forward			unidirectional		forward_list, unordered containers
Bi-directional	both direction		list, map, multi-map, set, multi-set
Random Access	both direction		Array, c-style array, vector, string, deque

stack, queue, priority-que - no iterator support
*/

/*begin(), end(), advance(), next(), prev(), copy(), inserter() */
void general_functions(void)
{
	int iarr[10] = {10,20,30,40,50,60,70,80,90,100};
	
	vector<int> icoll;
	
	register int i;
	for(i=0; i<10; ++i)
		icoll.push_back(iarr[i]);
	
	vector<int>::iterator pos;

	cout<<"######vector print()######"<<endl;
	
	for(pos = icoll.begin(); pos < icoll.end(); ++pos)
		cout<<" "<<*pos<<endl;

	cout<<"#####advance()#######"<<endl;

	pos = icoll.begin();
	advance(pos, 2);

	for(; pos < icoll.end(); ++pos)
		cout<<" "<<*pos<<endl;

	cout<<"#####next()#######"<<endl;

	pos = icoll.begin();
	pos = next(pos, 3);

	for(; pos < icoll.end(); ++pos)
		cout<<" "<<*pos<<endl;

	cout<<"#####prev()#######"<<endl;

	pos = icoll.end();
	pos = prev(pos, 5);

	for( ; pos < icoll.end(); ++pos)
		cout<<" "<<*pos<<endl;

	cout<<"#####inserter()#####"<<endl;

	int sarr[5] = {11,21,31,41,51};
	vector<int> scoll;
	vector<int>::iterator spos;

	for(i=0; i<5; ++i)
		scoll.push_back(sarr[i]);

	pos = icoll.begin();
	spos = scoll.begin();
	advance(pos, 3);
	copy(icoll.begin(), icoll.end(), inserter(scoll, pos));

	for(pos = icoll.begin(); pos < icoll.end(); ++pos)
		cout<<" "<<*pos<<endl;
}

void input_iterator(void)
{
	/* weakest iterator; moves only in forward direction; only read, cannot write
	 * usability - single pass algorithm
	 * operators - allowed(==,!=), not allowed(<=,>=)
	 * dereferencing - *ptr, access ptr->m (m = member function)
	 * incrementable - ++ only, no --
	 * swappable - 2 iterator elements can be swapped
	 * used - copy(), find()
	 * arithmetic calculation - not allowed - A+1,A+2
	 */

	/* *iter				Provides read access to the actual element
		iter->member		Provides read access to a member of the actual element
		++iter				Steps forward (returns new position)
		iter++				Steps forward
		iter1 == iter2		Returns whether two iterators are equal
		iter1 != iter2		Returns whether two iterators are not equal
		TYPE(iter)			Copies iterator (copy constructor)
	 */
}

void output_iterator(void)
{
	/* unidirectional; can write, no read
	 * usability - single pass algorithms only
	 * operators - cannot use ==, !=
	 * dereferencing - *ptr, ptr->m
	 * incremental - only use ++, no --
	 * swappable - 2 iterators can be swapped
	 * used - move, find algorithms
	 * arithmetic calculation - not allowed - A+1,A+2
	 */

	/* *iter = val			Writes val to where the iterator refers
		++iter				Steps forward (returns new position)
		iter++				Steps forward (returns old position)
		TYPE(iter)			Copies iterator (copy constructor)
	 */
}

void forward_iterator(void)
{
	/* unidirectional, can read & write
	 * usability - multi-pass algorithms
	 * operators - allowed(==,!=), not-allowed(<=,>=)
	 * dereferencing - same as input & output iterators
	 * incremental - ++A, A++ Ok, --A, A-- not OK
	 * swappable - 2 iterators can be swapped
	 * used - replace(), reverse_copy()
	 * arithmetic calculation - not allowed - A+1,A+2
	 */	

	/* *iter				Provides access to the actual element
		iter->member		Provides access to a member of the actual element
		++iter				Steps forward (returns new position)
		iter++				Steps forward (returns old position)
		iter1 == iter2		Returns whether two iterators are equal
		iter1 != iter2		Returns whether two iterators are not equal
		TYPE()				Creates iterator (default constructor)
		TYPE(iter)			Copies iterator (copy constructor)
		iter1 = iter2		Assigns an iterator
	*/
	int arr[10] = {9,8,7,6,5,4,3,2,1,10};

	vector<int> coll;

	register int i;
	for(i=0; i<10; ++i)
		coll.push_back(arr[i]);

	vector<int>::iterator pos;

	for(pos = coll.begin(); pos < coll.end(); ++pos)
		*pos = 100; //updating iterator value

	for(i = 0; i<10; ++i)
		cout<<" "<<arr[i]<<endl;
		
	for(pos = coll.begin(); pos < coll.end(); ++pos)
		cout<<" "<<(*pos)<<endl;
}

void bidirectional_iterator(void)
{

	/* bi-directional, can read & write
	 * usability - multi-pass algorithms
	 * operators - allowed(==, !=)
	 * dereferencing - *A, A->m
	 * incremental - A++, ++A
	 * decremental - A--, --A
	 * swappable - yes
	 * used - reverse_copy(), random_shuffle()
	 * can be used in place of forward, input & output iterators
	 * Arithmetic operation - not allowed
	 */

	/*	--iter				Steps backward (returns new position)
		iter--				Steps backward (returns old position)
	 */
	int arr[10] = {9,8,7,6,5,4,3,2,1,10};

	list<int> coll;
	list<int>::iterator pos;

	register int i;
	for(i=0; i<10; ++i)
		coll.push_back(arr[i]);

	for(pos = coll.end(); pos!=coll.begin(); --pos)
	{
		if (pos != coll.end()) {
			cout<<" "<<(*pos)<<endl;
		}
	}
	cout<<" "<<(*pos)<<endl; //last value from reverse
	return;
}

void random_access_iterator(void)
{
	/* bi-directional, can read & write
	 * Usability - multi-pass algorithms, random access of data
	 * Dereferencing - both lvalue & rvalue, *A, A->m
	 * Operators - ==, !=, >, <
	 * Incremental - A++, --A
	 * Decremental - A--, --A
	 * Swappable - yes
	 * Arithmetic operation - allowed A+1, A+2.. etc
	 * used - random_shuffle();
	 * index access - A[i] allowed
	 * strongest iterator so can be used in place of any other iterator
	 */

	/*	iter[n]				Provides access to the element that has index n
		iter+=n				Steps n elements forward (or backward, if n is negative)
		iter-=n				Steps n elements backward (or forward, if n is negative)
		iter+n				Returns the iterator of the nth next element
		n+iter				Returns the iterator of the nth next element
		iter-n				Returns the iterator of the nth previous element
		iter1-iter2			Returns the distance between iter1 and iter2
		iter1<iter2			Returns whether iter1 is before iter2
		iter1>iter2			Returns whether iter1 is after iter2
		iter1<=iter2		Returns whether iter1 is not after iter2
		iter1>=iter2		Returns whether iter1 is not before iter2
	 */

	int arr[10] = {11,21,31,41,51,61,71,81,91,101};
	int *ptr = arr;

	vector<int> coll;
	//vector<int>::iterator pos;

	register int i;
	for(i=0; i<10; ++i)
		coll.push_back(arr[i]);

	cout<<"######vector print()######"<<endl;
	for(auto pos = coll.begin(); pos < coll.end(); ++pos)
		cout<<"  "<<*pos;
	cout<<endl;

	cout<<"######change values######"<<endl;
	for(auto pos = coll.begin(); pos < coll.end(); ++pos)
		*pos = 1001;
	for(auto pos = coll.begin(); pos < coll.end(); ++pos)
		cout<<" "<<*pos<<" "<<*ptr++;
	cout<<endl;

	cout<<"######reverse print######"<<endl;	
	vector<int>::iterator pos;
	for(pos = coll.end(); pos > coll.begin(); --pos)
	{
		if (pos != coll.end())
			cout<<" "<<*pos;
	}
	cout<<" "<<*pos;
	cout<<endl;

	cout<<"######increment & index print ######"<<endl;
	auto cpos = coll.begin();
	for(i=0; i<10; ++i)
	{
		cpos[i] += i;
		cout<<" "<<cpos[i];
	}

	cout<<"###############"<<endl;
	return;
}

void check_iterator()
{
	general_functions();

	input_iterator();

	output_iterator();

	forward_iterator();

	bidirectional_iterator();

	random_access_iterator();
}