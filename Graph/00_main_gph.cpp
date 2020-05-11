
#if 1

#include <stdio.h>

//graph representation
extern void adj_matrix_rpstn(void);
extern void adj_list_rpstn(void);
extern void edge_list_rpstn(void);

//graph traversal
extern void depth_first_search(void);
extern void breadth_first_search(void);
extern void solve_grid(void);

int main()
{
	/* different graph representations */
	adj_matrix_rpstn();
	adj_list_rpstn();
	edge_list_rpstn();

	/* graph traversals */
	depth_first_search();
	breadth_first_search();

	/* graph problems */
	solve_grid();

	return 0;
}


#endif
