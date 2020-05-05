
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
extern void few_comparison_bs();
extern void find_floor_bs();
extern void find_occurences_bs();
extern void custom_binary_srch();
//circular list
extern void circular_list_srch();
//doubly linked list
extern void doubly_ll_srch();

int main()
{
	/* sequential search */
//	arr_sequential_srch();
	list_sequential_srch();

	/* reordering for maximum efficiency */
	arr_optmz_seq_srch();
	list_optmz_seq_srch();

	/* indexed sequential search */
	arr_indxd_seq_srch();
	list_indxd_seq_srch();

	/* binary search */
	iter_binary_srch();
	recur_binary_srch();
	few_comparison_bs();
	find_floor_bs();
	find_occurences_bs();
	custom_binary_srch();

	/* circular list search */
	circular_list_srch();

	/* doubly linked list search */
	doubly_ll_srch();

	return 0;
}



#endif