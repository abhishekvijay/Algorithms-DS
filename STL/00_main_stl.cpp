
#if 1

#include <stdio.h>

//iterators
extern void check_iterator(void);

//sequence containers
extern void check_vector(void);
extern void check_list(void);
extern void check_dequeue(void);
extern void check_arrays(void);
extern void check_forward_list(void);
extern void check_pair(void);

//container adaptors
//associative containers
//unordered associative containers
//algorithms
//functors, iterators, pair

int main()
{
	/* iterators */
//	check_iterator();

	/* sequence containers */
/*	check_vector();
	check_list();
	check_dequeue();
	check_arrays();
	check_forward_list();
*/
	check_pair();

	/* container adaptors */
	/* associative containers */
	/* unordered associative containers */
	/* algorithms */
	/*functors, iterators, pair */

	return 0;
}



#endif