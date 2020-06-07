
#if 1

#include <stdio.h>

extern void subset_sum(void);
extern void knapsack_01(void);
extern void unbounded_knapsack(void);

extern void permutation_coeff(void);
extern void binomial_coeff(void);
extern void bell_number(void);
extern void catalan_num(void);
extern void fibonacci_num(void);
extern void ugly_numbers(void);

int main()
{
/*	ugly_numbers();
	fibonacci_num();
	catalan_num();
	bell_number();
	binomial_coeff();
	permutation_coeff();
*/
	knapsack_01();

	unbounded_knapsack();

	return 0;
}


#endif