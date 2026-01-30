#include <stdio.h>
#include <limits.h>
#include <float.h>
/*
   Program Name: CheckLimits.cpp
   Author: GT
   This program displays the limits of various C/C++ data types in this platform
*/

int main(void) {
	printf("--------------------------------------------\n");
	printf("Maximum value of unsigned char : %u\n", (unsigned)UCHAR_MAX);
	printf("Minimum value of char : %d\n", CHAR_MIN);
	printf("Maximum value of char : %d\n", CHAR_MAX);
	printf("Minimum value of signed char : %d\n", SCHAR_MIN);
	printf("Maximum value of signed char : %d\n", SCHAR_MAX);
    printf("--------------------------------------------\n");
    printf("Maximum value of unsigned short : %u\n", (unsigned)USHRT_MAX);
	printf("Minimum value of short : %d\n", SHRT_MIN);
	printf("Maximum value of short : %d\n", SHRT_MAX);
	printf("--------------------------------------------\n");
	printf("Minimum value of int : %d\n", INT_MIN);
	printf("Maximum value of int : %d\n", INT_MAX);
	printf("--------------------------------------------\n");
	printf("Minimum value of long : %ld\n", (long)LONG_MIN);
	printf("Maximum value of long : %ld\n", (long)LONG_MAX);
	printf("--------------------------------------------\n");
	printf("Minimum negative normalized floating point number : %e\n", -1.*FLT_MIN);
	printf("Minimum normalized floating point number : %e\n", FLT_MIN);
	printf("Maximum negative floating point number : %e\n", -1.*FLT_MAX);
	printf("Maximum floating point number : %e\n", FLT_MAX);
    printf("--------------------------------------------\n");
	printf("Minimum negative normalized double floating point number : %e\n", -1.*DBL_MIN);
	printf("Minimum normalized double floating point number : %e\n", DBL_MIN);
	printf("Maximum negative double floating point number : %e\n", -1.*DBL_MAX);
	printf("Maximum double floating point number : %e\n", DBL_MAX);
    printf("--------------------------------------------\n");

   return 0;
} //end of main
