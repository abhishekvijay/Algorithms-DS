
#if 0

#include <stdio.h>

#define MAX		100

void iter_strcpy(char *str1, char* str2)
{
	register int i;
	for(i=0; str2[i] != '\0'; i++)
		str1[i] = str2[i];
	str1[i] = '\0';
	return;
}

void rec_strcpy(char *str1, char *str2)
{
	*str1 = *str2;
	str1++; str2++;

	if (*str2 == '\0')
		return;

	rec_strcpy(str1, str2);
}

void swap_both(char *str1, char* str2)
{
	char temp[MAX] = {'\0',};

	rec_strcpy(temp, str1);
	rec_strcpy(str1, str2);
	rec_strcpy(str2, temp);

	return;
}

int main()
{
	char str1[MAX] = "ThisIsIndia";
	char str2[MAX] = "MyCountryIsGreat";

	printf("before \n");
	printf("str1 - %s\n", str1);
	printf("str2 - %s\n", str2);

	rec_strcpy(str1, str2);

	iter_strcpy(str1, "ThisIsIndia");

	swap_both(str1, str2);

	printf("after \n");
	printf("str1 - %s\n", str1);
	printf("str2 - %s\n", str2);	

	return 0;
}

#endif