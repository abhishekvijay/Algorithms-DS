

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

}

void check_iterator()
{
//	general_functions();

//	input_iterator();

//	output_iterator();

//	forward_iterator();

	bidirectional_iterator();

	random_access_iterator();
}