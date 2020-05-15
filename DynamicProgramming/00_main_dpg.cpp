
#if 1

#include <stdio.h>

extern void ugly_numbers(void);
extern void fibonacci_num(void);
extern void catalan_num(void);
extern void bell_number(void);
extern void binomial_coeff(void);
extern void permutation_coeff(void);

int main()
{
	ugly_numbers();
	fibonacci_num();
	catalan_num();
	bell_number();
	binomial_coeff();
	permutation_coeff();

	return 0;
}


#endif