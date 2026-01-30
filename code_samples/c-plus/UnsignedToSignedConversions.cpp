#include <stdio.h>
#include <limits.h>

/*************************************************************************************
  Program Name: UnsignedToSignedCoversions.cpp
  Author: GT
  This program shows how to prevent problems when converting unsigned integers to
  other unsigned integers of lower precision and to signed integers
**************************************************************************************/

int main(void) {

	signed short int sSInt;      // A signed short int variable for demostration
	signed int sInt;	         // A signed int variable for demostration
	signed long int sLInt;       // A signed long int variable for demostration

	unsigned short int uSInt;    // An unsigned short int variable for demostration
	unsigned int uInt;	         // An unsigned int variable for demostration
	unsigned long int uLInt;     // An unsigned long int variable for demostration

	unsigned short int uSInt2;   // Auxiliar unsigned short int variable for demostration
	unsigned int uInt2;	         // Auxiliar unsigned int variable for demostration

    // The following are large values that will not convert to lower precisions
	uSInt = USHRT_MAX;    // Largest unsigned short int value
	uInt  = UINT_MAX;     // Largest unsigned int  value
	uLInt = ULONG_MAX;    // Largest unsigned long int value

	// The following are values that will convert to lower precisions
	/*
		uSInt = USHRT_MAX/3;
		uInt  = USHRT_MAX-1;
		uLInt = ULONG_MAX/3;
    */

	printf(" ----------------------------------------------------------------------------\n");
	printf("    Ways to Prevent Conversion Problems with Unsigned And Signed Integers \n");
	printf(" ----------------------------------------------------------------------------\n");

	// 1. Converting Unsigned Integers into a Unsigned Integers of a lower precision

	printf("     Converting Unsigned Integer onto Unsigned Integer of Lower Precision\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If Unsigned Integer is converted to another Unsigned of Lower Precision,\n");
	printf(" check the appropriate range of values. For example:\n");
	printf("\n 1. If converting unsigned long int to unsigned int, check:\n");
	printf("           if (UINT_MAX < uLInt)\n\n");
	printf("Trying to convert unsigned long int (%lu) into unsigned int ... \n", uLInt);

	if (UINT_MAX < uLInt) {
		printf("    Conversion is not possible, even with casting to unsigned int.\n");
		uInt2 = (unsigned int) uLInt;
		printf("    If forced, %lu is badly converted to : %u .\n", uLInt, uInt2);
	}
	else {
		uInt2 = uLInt;
		printf("    %lu converted to unsigned integer: %u .\n", uLInt, uInt2);
	}

	printf("\n 2. If converting unsigned int to unsigned short int, check:\n");
	printf("           if (USHRT_MAX < uInt)\n\n");
	printf(" Trying to convert unsigned int (%u) into unsigned short int... \n", uInt);

	if (USHRT_MAX < uInt) {
		printf("    Conversion is not possible, even with casting to unsigned short int.\n");
		uSInt2 = (unsigned short int) uInt;
		printf("    If forced, %u is badly converted to : %u .\n", uInt, uSInt2);
	}
	else {
		uSInt2 = uInt;
		printf("    %u converted to unsigned short integer: %u .\n", uInt, uSInt2);
	}
	printf(" ----------------------------------------------------------------------------\n");


	// 2. Converting Unsigned Integers into a Signed Integers

	printf("     Converting Unsigned Integer onto Signed Integer\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If Unsigned Integer is converted to a Signed one,\n");
	printf(" check the appropriate range of values. For example:\n");
	printf("\n 1. If converting unsigned long int to signed long int, check:\n");
	printf("           if (LONG_MAX < uLInt)\n\n");
	printf(" Trying to convert unsigned long int (%lu) into signed long int ... \n", uLInt);

	if (LONG_MAX < uLInt) {
		printf("    Conversion is not possible, even with casting to signed long int.\n");
		sLInt = (signed long int) uLInt;
		printf("    If forced, %lu is badly converted to : %ld .\n", uLInt, sLInt);
	}
	else {
		sLInt = uLInt;
		printf("    %lu converted to signed long integer: %ld .\n", uLInt, sLInt);
	}

	printf("\n 2. If converting unsigned int to signed int, check:\n");
	printf("           if (INT_MAX < uInt)\n\n");
	printf(" Trying to convert unsigned int (%u) into signed int ... \n", uInt);

	if (INT_MAX < uInt) {
		printf("    Conversion is not possible, even with casting to signed int.\n");
		sInt = (signed int) uInt;
		printf("    If forced, %u is badly converted to : %d .\n", uInt, sInt);
	}
	else {
		sInt = uInt;
		printf("    %u converted to signed integer: %d .\n", uInt, sInt);
	}

	printf("\n 3. If converting unsigned short int to signed short int, check:\n");
	printf("           if (SHRT_MAX < uSInt)\n\n");
	printf(" Trying to convert unsigned short int (%u) into signed short int... \n", uSInt);

	if (SHRT_MAX < uSInt) {
		printf("    Conversion is not possible, even with casting to signed short int.\n");
		sSInt = (signed short int) uSInt;
		printf("    If forced, %u is badly converted to : %d .\n", uSInt, sSInt);
	}
	else {
		sSInt = uSInt;
		printf("    %u converted to signed integer: %d .\n", uSInt, sSInt);
	}
	printf("\n ----------------------------------------------------------------------------\n");

	return 0;
}  // end of main
