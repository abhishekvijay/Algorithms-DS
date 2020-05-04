
#if 1

#include <stdio.h>

//sequential search
extern void arr_sequential_srch();
extern void list_sequential_srch();
//optimzed sequential search
extern void arr_optmz_seq_srch();
extern void list_optmz_seq_srch();
//indexed sequential search
extern void arr_indxd_seq_srch();
extern void list_indxd_seq_srch();
//binary search
extern void iter_binary_srch();
extern void recur_binary_srch();
extern void custom_binary_srch();
//circular list
extern void circular_list_srch();
//doubly linked list
extern void doubly_ll_srch();

int main()
{
	/* sequential search */
	arr_sequential_srch();
	list_sequential_srch();

	/* reordering for maximum efficiency */
	arr_optmz_seq_srch();
	list_optmz_seq_srch();

	/* indexed sequential search */
	arr_indxd_seq_srch();
	list_indxd_seq_srch();

	/* binary search */
//	iter_binary_srch();
//	recur_binary_srch();
	custom_binary_srch();

	/* circular list search */
	circular_list_srch();

	/* doubly linked list search */
	doubly_ll_srch();

	return 0;
}



#endif