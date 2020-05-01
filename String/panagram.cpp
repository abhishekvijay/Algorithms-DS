
#if 0

#include <stdio.h>

#define MAX		100
#define MAXA	26

int getStrLen(char *str)
{
	if (str == NULL)
		return 0;

	int cnt = 0;

	while(*str != '\0')
	{
		cnt++;
		str++;
	}
	return cnt;
}

int IsPanagram(char *str)
{
	int count[MAXA] = {0, };
	register int i;

#if WITH_USING_STRING_LENGTH
	int len = getStrLen(str);

	if (len == 0)
		return 0; //not a valid string	

	for(i=0; i<len; ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') //65~90
			count[str[i] - 'A'] = 1;
		else if (str[i] >= 'a' && str[i] <= 'z') //97~122
			count[str[i] - 'a'] = 1;
		else if (str[i] == ' ')
			continue;
		else 
			return 0; //not a valid string
	}

#else //WITHOUT_USING_STRING_LENGTH

	if (str == NULL)
		return 0;

	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
			count[*str-'A'] = 1;
		else if (*str >= 'a' && *str <= 'z')
			count[*str-'a'] = 1;
		else if (*str == ' ')
		{
			str++;
			continue;
		}
		else
			return 0;

		str++;
	}

#endif

	for(i=0; i<MAXA; ++i)
		if (count[i] == 0)
			return 0;

	return 1;
}

int main()
{
	char str1[MAX] = "The quick brown fox jumps over the lazy dog";
	char str2[MAX] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
	char str3[MAX] = "A1B2C3D4E5";
	char str4[MAX] = "123456789";
	char str5[MAX] = "";

	if (IsPanagram(str1))
		printf("String is Panagram\n");
	else
		printf("Not a Panagram\n");

	if (IsPanagram(str2))
		printf("String is Panagram\n");
	else
		printf("Not a Panagram\n");

	if (IsPanagram(str3))
		printf("String is Panagram\n");
	else
		printf("Not a Panagram\n");

	if (IsPanagram(str4))
		printf("String is Panagram\n");
	else
		printf("Not a Panagram\n");

	if (IsPanagram(str5))
		printf("String is Panagram\n");
	else
		printf("Not a Panagram\n");
	
	return 0;
}


#endif