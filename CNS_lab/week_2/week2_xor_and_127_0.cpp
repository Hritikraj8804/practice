//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//int main()
//{
//	char str[] = "Hello World!";
//	char str1[13];
//	char str2[13];
//	int i, len;
//	len = strlen(str);
//	
//	printf("%s\n", str);
//	for(i = 0; i < len; i++)
//	{
//		str1[i] = str[i]&127;	
//	}
//	printf("%s", str1);
//	str1[len] = '\0';
//	printf("\n");
//	
//	for(i = 0; i < len; i++)
//	{
//		str2[i] = str[i]^127;
//	}
//	printf(" %s", str2);
//	str2[len] = '\0';
//	printf("\n");
//	
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[] = "Hello World!";
    char str1[13];
    char str2[13];
    int i, len;
    len = strlen(str);
    
    printf("Original: %s\n", str);
    
    // Apply & 127 (this effectively does nothing to ASCII characters in this range)
    for(i = 0; i < len; i++)
    {
        str1[i] = str[i] & 127;  // Mask the 8th bit (this is redundant for standard ASCII)
    }
    str1[len] = '\0';  // Null-terminate the string
    printf("Modified with &127: %s\n", str1);
    
    // Apply ^ 127 (invert all bits, which will change the characters drastically)
    for(i = 0; i < len; i++)
    {
        str2[i] = str[i] ^ 127;  // Toggle all bits of each character
    }
    str2[len] = '\0';  // Null-terminate the string

    // Print ASCII values of str2 characters to debug
    printf("Modified with ^127 (ASCII values): ");
    for(i = 0; i < len; i++) {
        printf("%d ", (unsigned char)str2[i]);
    }
    printf("\n");

    // Optionally, print the characters as well
    printf("Modified with ^127: %s\n", str2);
    
    return 0;
}

