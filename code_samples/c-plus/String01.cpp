#include <stdio.h>
#include <string.h>


// Program Name: String01.cpp
// Author: GT
// This program will show how to use C strings

int main(void)
{
	// Arrays of characters to show strings C
	char s1[] = "To be or not to be.";
	char s2[30] = "small";
	char s3[] = { 'c', 'h','a', 'r', 'b', 'y', 'c', 'h','a', 'r', '\0'};
	char s4[30];

	// Initializing a string using strcpy
    strcpy(s4, s1);

    // Printing the Strings and use of strlen
    printf("s1=[%s] length of s1 = %zu\n", s1, strlen(s1));
    printf("s2=[%s] length of s2 = %zu\n", s2, strlen(s2));
    printf("s3=[%s] length of s3 = %zu\n", s3, strlen(s3));
    printf("s4=[%s] length of s4 = %zu\n", s4, strlen(s4));


    //modifying individual  characters
    s2[0]='l';
    s2[1]='a';
    s2[2]='r';
    s2[3]='g';
    s2[4]='e';
	printf("s2=[%s] length of s2 = %zu\n", s2, strlen(s2));

	// use of a loop
    for (size_t i = 0; i < strlen(s3); i++) {
		if (s3[i] == 'r') {
			s3[i] = 't';
		}
	}

    printf("s3=[%s] length of s3 = %zu\n", s3, strlen(s3));

	// concatenation of characters
	strcat(s2,s3);
    printf("s2=[%s] length of s2 = %zu\n", s2, strlen(s2));
	strncat(s2,s1,5);
    printf("s2=[%s] length of s2 = %zu\n", s2, strlen(s2));

	return 0;
}
