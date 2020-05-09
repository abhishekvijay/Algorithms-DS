

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

void gerneral_functions(void)
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
	 *
	 * used - copy(), find()
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
	 * used - replace, reverse_copy
	 */
}

void bidirectional_iterator(void)
{

}

void random_access_iterator(void)
{

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