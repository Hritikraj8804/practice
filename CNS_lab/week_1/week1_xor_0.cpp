#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[] = "Hello World!";
	char str1[13];
	int i, len;
	len = strlen(str);
	
	printf("%s\n", str);
	for(i = 0; i < len; i++)
	{
		str1[i] = str[i]^0;
		printf("%c", str1[i]);
	}
	
	printf("\n");
}
