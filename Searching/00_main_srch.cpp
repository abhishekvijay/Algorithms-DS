
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
extern void matrix_search();
extern void search_bitonic_array();
extern void max_element_bitonic_array();
extern void binary_search_on_answer();
extern void minimum_diff_elmnt();
extern void index_of_first_1_binary_array();
extern void poistion_in_infinite_sorted_array();
extern void next_letter_problem();
extern void ciel_element();
extern void floor_element();
extern void searching_nearly_sorted_array();
extern void find_element_sorted_rotated_array();
extern void rotation_sorted_array();
extern void element_count();
extern void occurences_of_element();
extern void order_agnostic_bs();
extern void ascending_bs();
extern void descending_bs();

extern void custom_binary_srch();
extern void find_occurences_bs();
extern void find_floor_bs();
extern void few_comparison_bs();
extern void recur_binary_srch();
extern void iter_binary_srch();
//circular list
extern void circular_list_srch();
//doubly linked list
extern void doubly_ll_srch();

int main()
{
/*	//sequential search
	arr_sequential_srch();
	list_sequential_srch();

	//reordering for maximum efficiency
	arr_optmz_seq_srch();
	list_optmz_seq_srch();

	//indexed sequential search//
	arr_indxd_seq_srch();
	list_indxd_seq_srch();
*/
	//binary search//
	matrix_search();
	search_bitonic_array();
	max_element_bitonic_array();
	binary_search_on_answer();
	minimum_diff_elmnt();
	index_of_first_1_binary_array();
	poistion_in_infinite_sorted_array();
	next_letter_problem();
	ciel_element();
	floor_element();
	searching_nearly_sorted_array();
	find_element_sorted_rotated_array();
	rotation_sorted_array();
	element_count();
	occurences_of_element();
	order_agnostic_bs();
	ascending_bs();
	descending_bs();
	
/*	custom_binary_srch();
	find_occurences_bs();
	find_floor_bs();
	few_comparison_bs();
	recur_binary_srch();
	iter_binary_srch();

	//circular list search//
	circular_list_srch();

	// doubly linked list search //
	doubly_ll_srch();
*/
	return 0;
}



#endif