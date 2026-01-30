#include <stdio.h>
/*
   Program Name: CheckSizes.cpp
   Author: GT
   This program displays the sizes assigned to various C/C++ data types in this platform.
   It uses the sizeof() operator that gives the actual size in bytes of its parameter (input)
*/

int main(void) {
	printf("--------------------------------------------\n");
	printf( "Size of unsigned char : %zu\n", sizeof(unsigned char));
	printf("Size of char : %zu\n", sizeof(char));
	printf("Size of signed char : %zu\n", sizeof(signed char));
    printf("--------------------------------------------\n");
    printf("Size of unsigned short int : %zu\n", sizeof(unsigned short int));
    printf("Size of short int : %zu\n", sizeof(short int));
    printf("Size of signed short int : %zu\n", sizeof(signed short int));
	printf("--------------------------------------------\n");
	printf( "Size of unsigned int : %zu\n", sizeof(unsigned int));
    printf("Size of int : %zu\n", sizeof(int));
    printf("Size of signed int : %zu\n", sizeof(signed int));
	printf("--------------------------------------------\n");
	printf("Size of unsigned long int : %zu\n", sizeof(unsigned long int));
    printf( "Size of long int : %zu\n", sizeof(long int));
    printf("Size of signed long int : %zu\n", sizeof(signed long int));
    printf("--------------------------------------------\n");
    printf( "Size of float : %zu\n", sizeof(float));
    printf( "Size of double : %zu\n", sizeof(double));
    printf("--------------------------------------------\n");
    printf( "Size of wchar_t : %zu\n", sizeof(wchar_t));
    printf("--------------------------------------------\n");

   return 0;
} //end of main
