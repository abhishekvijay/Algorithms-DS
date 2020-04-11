
#if 0

#include <stdio.h>

void insertion_sort(int *ptr, int st, int en)
{
	int val, i, j;

	for(i=1; i<en; i++)
	{
		val = ptr[i];

		for(j=i-1; j>=0 && ptr[j]>val; j--)
				ptr[j+1] = ptr[j];
		ptr[j+1] = val;
	}
}

int main()
{
	int arr[10] = {34,12,67,92,10,6,56,86,74,2};

	insertion_sort(arr, 0, 10);

	for(register int i=0; i<10; ++i)
		printf("%d ", arr[i]);

	return 0;
}

#endif

#if 0

#include<stdio.h>
#include<string.h>

int main()
{
	char str[10][20],temp[20];
	int i=0,j=0,n;
	
	printf("Enter the number of items\n");
	
	scanf("%d",&n);
	
	printf("Enter the items\n");
	
	while(i<n)
		scanf("%s",str[i++]);

	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(strcmp(str[j-1],str[j])>0)
			{
				strcpy(temp,str[j-1]); 
				strcpy(str[j-1],str[j]);
				strcpy(str[j],temp);
			}
		}
	}
	
	printf(" \nSorted Items\n");
	
	for(i=0;i<n;i++)
		printf(" %s\n",str[i]);
}

#endif