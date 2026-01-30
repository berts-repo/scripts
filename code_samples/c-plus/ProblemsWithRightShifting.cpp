#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

/* Returns the number of set bits */
size_t precision(uintmax_t num) {
	size_t precision = 0;
	while (num != 0) {
		if (num % 2 == 1) {
			precision++;
		}
		num >>= 1;
	}
	return precision;
}


/*************************************************************************************
  Program Name: ProblemsWithRightShifting.cpp
  Author: GT
  This program shows how to prevent problems with Right Shifting
**************************************************************************************/

int main(void) {

    unsigned int uInt1;      // Value to be shifted
    unsigned int uInt2;      // Number of positins to be shifted
    unsigned int uResult;    // The result of the shifting operation on unsigned int

    signed int sInt1;      // Value to be shifted
    signed int sInt2;      // Number of positins to be shifted
    signed int sResult;     // The result of the shifting operation on signed int

	printf(" ----------------------------------------------------------------------------\n");
	printf("                     Preventing Underflow in Right Shifting \n");
	printf(" ----------------------------------------------------------------------------\n");

    uInt1  = UINT_MAX;                 // Largest unsigned int value
    uInt2  = precision(UINT_MAX)-1;    // Shifting to the max

	printf("   1. Right Shifting of Unsigned types\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" When right-shifting an unsigned integer, it should be done\n");
	printf(" no more than the precision of the data type.\n");
	printf(" Example: An unsigned int can be shifted %d positions.\n", uInt2);
	printf(" Check beforehand that the shift will be no more than\n");
	printf(" the precision of the maximum number:\n");
	printf("        if (uInt2 >= PRECISION(UINT_MAX))\n\n");
	printf("\n ... Trying to right shift %u times the unsigned int (%u) ... \n", uInt2,uInt1);

	if (uInt2  >= precision(UINT_MAX)) {
		printf("    Right Shifting not possible. It underflows.\n\n");
	}
	else {
		uResult = uInt1 >> uInt2 ;
		printf("    %u >> %u = %u \n\n", uInt1, uInt2, uResult);
	}

	uInt2++;    // Increasing the max shifting
	printf("\n ... Trying to right shift %u times the unsigned int (%u) ... \n", uInt2, uInt1);

	if (uInt2 >= precision(UINT_MAX)) {
		printf("    Right Shifting not possible. It underflows.\n\n");
	}
	else {
		uResult = uInt1 >> uInt2;
		printf("    %u >> %u = %u \n\n", uInt1, uInt2, uResult);
	}
	printf(" ----------------------------------------------------------------------------\n");

    sInt1  = INT_MAX;                       // Largest signed int value
    sInt2  = precision(INT_MAX)-1;    // Shifting to the max

	printf("   2. Right Shifting of Signed types\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" When right-shifting a signed integer, check that operands are positive and\n");
	printf(" it will not exceed the maximum number of shifts for its data type.\n");
	printf(" Example: A signed int can be shifted %d positions.\n", sInt2);
	printf(" Check beforehand that the operands are positive and\n");
	printf(" that it will not be shifted more than the precision of the maximum number:\n");
	printf("	if ( (sInt1<0) || (sInt2<0) ||\n");
	printf("         (sInt2 >= precision(INT_MAX)) \n\n");
	printf("\n ... Trying to right shift %d times the signed int (%d) ... \n", sInt2, sInt1);

	if ( (sInt1<0) || (sInt2<0) || 
		 (sInt2 >= precision(INT_MAX)) 
		) {
		printf("    Right Shifting not possible. It underflows.\n\n");
	}
	else {
		sResult = sInt1 >> sInt2 ;
		printf("    %d >> %d = %d \n\n", sInt1, sInt2, sResult);
	}

	sInt2++;    // Increasing the max shifting
	printf("\n ... Trying to right shift %d times the signed int (%d) ... \n", sInt2, sInt1);

	if ((sInt1<0) || (sInt2<0) ||
		(sInt2 >= precision(INT_MAX)) 
		) {
		printf("    Right Shifting not possible. It underflows.\n\n");
	}
	else {
		sResult = sInt1 >> sInt2;
		printf("    %d >> %d = %d \n\n", sInt1, sInt2, sResult);
	}
	printf(" ----------------------------------------------------------------------------\n");


	return 0;
}  // end of main
