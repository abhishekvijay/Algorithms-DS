
#if 1

#include <stdio.h>

//graph representation
extern void adj_matrix_rpstn();
extern void adj_list_rpstn();
extern void edge_list_rpstn();

//graph traversal
extern void depth_first_search();
extern void breadth_first_search();

int main()
{
//	adj_matrix_rpstn();
//	adj_list_rpstn();
//	edge_list_rpstn();

//	depth_first_search();
	breadth_first_search();

	return 0;
}


#endif