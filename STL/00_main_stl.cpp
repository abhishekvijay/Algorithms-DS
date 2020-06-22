
#if 1

#include <stdio.h>

//iterators
extern void check_iterator(void);

//sequence containers
extern void check_vector(void);
extern void check_list(void);
extern void check_deque(void);
extern void check_array(void);
extern void check_forward_list(void);
extern void check_pair(void);
extern void check_tuple(void);
extern void check_smart_pointers(void);
extern void check_multiset(void);
extern void check_multimap(void);
extern void check_uo_multiset(void);
extern void check_uo_multimap(void);
extern void check_algorithm(void);

//container adaptors
//associative containers
//unordered associative containers
//algorithms
//functors, iterators, pair

int main()
{
	/* sequence containers */
//	check_vector();
//	check_deque();
//	check_array();
//	check_list();	
//	check_forward_list();	

	/* associative containers */
//	check_multiset();
//	check_multimap(); 

	/* unordered containers */
//	check_uo_multiset();
//	check_uo_multimap();

	/* stl algorithm */
	check_algorithm();

	/* stl utilities */
//	check_pair();
//	check_tuple();
//	check_smart_pointers();

	/* iterators */
//	check_iterator();

	/* container adaptors */
	/* associative containers */
	/* unordered associative containers */
	/* algorithms */
	/*functors, iterators, pair */

	return 0;
}



#endif
