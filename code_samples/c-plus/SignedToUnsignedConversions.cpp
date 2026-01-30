#include <stdio.h>
#include <limits.h>

/*************************************************************************************
  Program Name: SignedToUnsignedCoversions.cpp
  Author: GT
  This program shows how to prevent problems when converting signed integers to
  other signed integers of lower precision and to unsigned integers
**************************************************************************************/

int main(void) {

	signed short int sSInt;      // A signed short int variable for demostration
	signed int sInt;	         // A signed int variable for demostration
	signed long int sLInt;       // A signed long int variable for demostration

	unsigned short int uSInt;    // An unsigned short int variable for demostration
	unsigned int uInt;	         // An unsigned int variable for demostration
	unsigned long int uLInt;     // An unsigned long int variable for demostration

	signed short int sSInt2;     // Auxiliar signed short int variable for demostration
	signed int sInt2;	         // Auxiliar signed int variable for demostration

    // The following are small values that will not convert to unsigned
	sSInt = SHRT_MIN;    // Smallest signed short int value
	sInt  = INT_MIN;     // Smallest signed int value
	sLInt = LONG_MIN;    // Smallest signed long int value

	// The following are values that will convert to lower precisions
	/*
		sSInt = SHRT_MAX/3;
		sInt  = SHRT_MAX-1;
		sLInt = LONG_MAX/3;
		*/

	printf(" ----------------------------------------------------------------------------\n");
	printf("    Ways to Prevent Conversion Problems with Signed Integers \n");
	printf(" ----------------------------------------------------------------------------\n");

	// 1. Converting Signed Integers into a Signed Integers of a lower precision

	printf("     Converting Signed Integer onto Signed Integer of Lower Precision\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If Signed Integer is converted to another Signed of Lower Precision,\n");
	printf(" check the appropriate range of values. For example:\n");
	printf("\n 1. If converting signed long int to signed int, check:\n");
	printf("           if ((INT_MAX < sLInt) || (INT_MIN > sLInt))\n\n");
	printf("Trying to convert signed long int (%ld) into signed int ... \n", sLInt);

	if ((INT_MAX < sLInt) || (INT_MIN > sLInt)) {
		printf("    Conversion is not possible, even with casting to signed int.\n");
		sInt2 = (signed int) sLInt;
		printf("    %ld converted to signed integer: %d .\n", sLInt, sInt2);
	}
	else {
		sInt2 = sLInt;
		printf("    %ld converted to signed integer: %d .\n", sLInt, sInt2);
	}

	printf("\n 2. If converting signed int to signed short int, check:\n");
	printf("           if ((SHRT_MAX < sInt) || (SHRT_MIN > sInt))\n\n");
	printf(" Trying to convert signed int (%d) into signed short int... \n", sInt);

	if ((SHRT_MAX < sInt) || (SHRT_MIN > sInt)) {
		printf("    Conversion is not possible, even with casting to signed short int.\n");
		sSInt2 = (signed short int) sInt;
		printf("    %d converted to signed short integer: %d .\n", sInt, sSInt2);
	}
	else {
		sSInt2 = sInt;
		printf("    %d converted to signed integer: %d .\n", sInt, sSInt2);
	}
	printf(" ----------------------------------------------------------------------------\n");


	// 2. Converting Signed Integers into an Unsigned Integers

	printf("     Converting Signed Integer onto Unsigned Integer\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If Signed Integer is converted to an Unsigned one,\n");
	printf(" check that the value is non negative. For example:\n");
	printf("\n 1. If converting signed long int to unsigned long int, check:\n");
	printf("           if (sLInt < 0)\n\n");
	printf(" Trying to convert signed long int (%ld) into unsigned long int ... \n", sLInt);

	if (sLInt < 0) {
		printf("    Conversion is not possible, even with casting to unsigned long int.\n");
		uLInt = (unsigned long int) sLInt;
		printf("    If forced, %ld is badly converted to : %lu .\n", sLInt, uLInt);
	}
	else {
		uLInt = sLInt;
		printf("    %ld converted to unsigned long integer: %lu .\n", sLInt, uLInt);
	}

	printf("\n 2. If converting signed int to unsigned int, check:\n");
	printf("           if (sInt < 0)\n\n");
	printf(" Trying to convert signed int (%d) into unsigned int ... \n", sInt);

	if (sInt < 0) {
		printf("    Conversion is not possible, even with casting to unsigned int.\n");
		uInt = (unsigned int) sInt;
		printf("    if forced, %d is badly converted to : %u .\n", sInt, uInt);
	}
	else {
		uInt = sInt;
		printf("    %d converted to unsigned integer: %u .\n", sInt, uInt);
	}

	printf("\n 3. If converting signed short int to unsigned short int, check:\n");
	printf("           if (sSInt < 0)\n\n");
	printf(" Trying to convert signed short int (%d) into unsigned short int... \n", sSInt);

	if (sSInt < 0) {
		printf("    Conversion is not possible, even with casting to unsigned short int.\n");
		uSInt = (unsigned short int) sSInt;
		printf("    If forced %d is badly converted to: %u .\n", sSInt, uSInt);
	}
	else {
		uSInt = sSInt;
		printf("    %d converted to unsigned short integer: %u .\n", sSInt, uSInt);
	}
	printf("\n ----------------------------------------------------------------------------\n");

	return 0;
}  // end of main
