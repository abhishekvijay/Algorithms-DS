
#include <stdio.h>

#define MAX		20
#define SWAP(x,y)		do { int temp = *x; *x = *y; *y = temp; } while(0);

// bubble sort
void csort(int *ptr, int sz)
{
	register int i, j;
	int IsFound = 1;

	for(i=0; i<sz && IsFound; i++)
	{
		IsFound = 0;

		for(j=0; j<sz-i; ++j)
		{
			if (ptr[j] > ptr[j+1])
			{
				IsFound = 1;
				SWAP(&ptr[j], &ptr[j+1]);
			}
		}
	}
	return;
}

void matrix_search()
{

}
void search_bitonic_array()
{

}

void max_element_bitonic_array()
{

}

void binary_search_on_answer()
{

}

void minimum_diff_elmnt()
{

}

void index_of_first_1_binary_array()
{

}

void poistion_in_infinite_sorted_array()
{

}

void next_letter_problem()
{

}

void ciel_element()
{

}

void floor_element()
{

}

void searching_nearly_sorted_array()
{

}

void find_element_sorted_rotated_array()
{

}

void rotation_sorted_array()
{

}

void element_count()
{

}

void occurences_of_element()
{

}

void order_agnostic_bs()
{

}

void ascending_bs()
{
	int arr[8] = {10,20,30,40,50,60,70,80};
	int item = 80;

	int st = 0, en = 7, mid = 0;

	while(st <= en)
	{
		mid = st + (en-st)/2;

		if (arr[mid] == item)
			break;
		else if (arr[mid] < item)
			st = mid + 1;
		else if (arr[mid] > item)
			en = mid - 1;
	}

	if (arr[mid] == item)
		printf("item found at indx - %d\n", mid);
	else
		printf("item not found\n");

	return;
}

void descending_bs()
{
	int arr[8] = {100,90,80,70,60,50,40,30};
	int item = 10;

	int st = 0;
	int en = 7;
	int mid = 0;

	while(st <= en)
	{
		mid = (st+en)/2;

		if (arr[mid] == item)
			break;
		else if (arr[mid] < item)
			en = mid-1;
		else if (arr[mid] > item)
			st = mid+1;
	}

	if (arr[mid] == item)
		printf("item found at indx - %d\n", mid);
	else
		printf("item not found\n");

	return;
}

int binary_stride(int a[], int sz, int item) 
{
    int stride = 0, pos = 0, temp = 0;
    
	for(stride = sz>>1; stride >= 1; stride /= 2) 
	{		
        while(pos+stride < sz && a[pos+stride] <= item) 
			pos += stride;
    }

    if(a[pos] == item) 
		return pos;

    return -1;
}
//this is not working correctly at this time
int custom_bs(int *ptr, int item, int sz)
{
	int mid = (sz>>1);
	int len = sz>>1;
	int pos = 0;

	while (item != ptr[mid])
	{
		if (item < ptr[mid])
		{
			mid -= (len>>1);
			pos  += len;
		}
		else
			mid += (len>>1);

		if (len == 0)
			return -1;

		len = len>>1;
	}

	if (item == ptr[mid])
		return mid;
	else
		return -1;
}

void custom_binary_srch()
{
	int arr[MAX] = {12,34,56,78,90,98,87,65,54,43,21,14,16,46,89,41,61,81,66,99};

	csort(arr, MAX-1);

	int itm = 99;

	printf("item srch - %d, found at index - %d\n", itm, binary_stride(arr, 20, itm));

	printf("item srch - %d, found at index - %d\n", itm, custom_bs(arr, itm, MAX));	

	return;
}

void find_occurences_bs()
{
	int arr[20] = {1,1,1,1,4,4,4,4,4,4,4,7,7,7,7,7,9,9,9,9};
	int lo, hi, mid, item, lres, rres;

	//find left most
	lo = 0; hi = 20; item = 9;

	while((hi-lo)>1)
	{
		mid = lo + (hi-lo)/2;

		if (item >= arr[mid])
			lo = mid;
		else
			hi = mid;
	}

	lres = lo;

	//find right most
	lo = 0; hi = 20;

	while((hi-lo) > 1)
	{
		mid = lo + (hi-lo)/2;

		if (item <= arr[mid])
			hi = mid;
		else
			lo = mid;
	}

	rres = hi;

	printf("Occurences - %d\n", lres-rres+1);
	return;
}

void find_floor_bs()
{
	int arr[8] = {-1, 2, 3, 5, 6, 8, 9, 10}; //no repitition
	int lo = 0, hi = 8;
	int mid = 0, item = 9;

	while((hi-lo)>1)
	{
		mid = lo + (hi-lo)/2;

		if (item <= arr[mid])
			hi = mid;
		else
			lo = mid;
	}

	printf("floor for item - %d is - %d\n", item, arr[lo]);	

	return;
}

void few_comparison_bs()
{
	int hi, lo, mid, item;

	int arr[MAX] = {12,34,56,78,90,98,87,65,54,43,21,14,16,46,89,41,61,81,66,99};

	csort(arr, MAX-1);

	lo = 0; hi = MAX;
	item = 81;

	while(hi-lo > 1)
	{
		mid = lo + ((hi-lo)>>1);

		if (arr[mid] <= item)
			lo = mid;
		else
			hi = mid;
	}

	if (arr[lo] == item)
		printf("item srch - %d, found at index - %d\n", item, lo);	
	else
		printf("item srch - %d, found at index - %d\n", item, -1);	
	return;
}

int iter_bs(int *ptr, int item, int sz)
{
	int mid = 0, lo = 0, hi = sz;	

	while(lo <= hi)
	{
		mid = lo + ((hi - lo)>>1);

		if (item == ptr[mid])
			return mid;
		else if (item < ptr[mid])
			hi = mid - 1;
		else if (item > ptr[mid])
			lo = mid + 1;
	}

	if (ptr[mid] == item)
		return mid;
	else
		return -1;
}

void iter_binary_srch()
{
	int arr[MAX] = {12,34,56,78,90,98,87,65,54,43,21,14,16,46,89,41,61,81,66,99};

	csort(arr, MAX-1);

	int itm = 99;

	printf("item srch - %d, found at index - %d\n", itm, iter_bs(arr, itm, MAX));	

	return;
}

int recur_bs(int *ptr, int item, int lb, int ub)
{
	int mid = 0;

	if (ub < lb)
		return -1;

	mid = (lb + ub) >> 1;

	return ((item == ptr[mid]) ? mid : ((item < ptr[mid]) ? recur_bs(ptr, item, lb, mid-1) : recur_bs(ptr, item, mid+1, ub)));
}

void recur_binary_srch()
{
	int arr[MAX] = {12,34,56,78,90,98,87,65,54,43,21,14,16,46,89,41,61,81,66,99};

	csort(arr, MAX-1);

	int itm = 65;

	printf("item srch - %d, found at index - %d\n", itm, recur_bs(arr, itm, 0, MAX));	

	return;
}
