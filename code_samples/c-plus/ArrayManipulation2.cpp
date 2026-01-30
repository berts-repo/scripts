#include <stdio.h>
#define SIZE 10
// the variable above is the size of an array in this program

// Program Name: ArrayManipulation2.cpp
// Author: GT
// Program to create and manipulate parallel arrays of numbers


int main(void)
{
    int iMin;                 // the smallest element of the int array
    int iMax;                 // the largest element of the int array
	int iTotal=0;             // the total of all elements in the int array

    float fMin;               // the smallest element of the float array
    float fMax;               // the largest element of the float array
	float fTotal=0.0;         // the total of all elements in the float array

    double dMin;              // the smallest element of the double array
    double dMax;              // the largest element of the double array
	double dTotal=0.0;        // the total of all elements in the double array

    double avgInt;            // average of elements in int array
    double avgFloat;          // average of elements in float array
    double avgDouble;         // average of elements in double array

	// Parallel arrays:
	//    1 An array of integers
	int iArray[SIZE] = {  10, 40, 70, 30, 20,
	                     100, 80, 60, 90, 50  } ;
	//    2 An array of float
	float fArray[SIZE] = { 102.5f, 140.5f, 370.6f, 113.7f, 220.1f,
	                       177.6f, 438.9f, 260.2f, 219.6f, 136.5f } ;
	//    2 An array of double
	double dArray[SIZE] = { 0.6711, 0.9834, 0.2062, 0.6912, 0.5631,
	                        0.5201, 0.5041, 0.6073, 0.7311, 0.1022 } ;

	// Evaluating the smallest element in all arrays
    iMin = iArray[0];
    fMin = fArray[0];
    dMin = dArray[0];
	for (int i=0; i<SIZE; i++) {
		if (iArray[i] < iMin ) { iMin = iArray[i]; }
		if (fArray[i] < fMin ) { fMin = fArray[i]; }
		if (dArray[i] < dMin ) { dMin = dArray[i]; }
	}

	// Evaluating the largest element in all arrays
    iMax = iArray[0];
    fMax = fArray[0];
    dMax = dArray[0];
	for (int i=0; i<SIZE; i++) {
		if (iArray[i] > iMax ) { iMax = iArray[i]; }
		if (fArray[i] > fMax ) { fMax = fArray[i]; }
		if (dArray[i] > dMax ) { dMax = dArray[i]; }
	}

	// Evaluating the addition of all elements in all arrays
	for (int i=0; i<SIZE; i++) {
			iTotal = iTotal + iArray[i];
			fTotal = fTotal + fArray[i];
			dTotal = dTotal + dArray[i];
	}

	// Evaluating the average of elements in all arrays
	avgInt    = iTotal/(1.0 * SIZE);
	avgFloat  = fTotal/ SIZE;
	avgDouble = dTotal/ SIZE;

	// printing the elements of all arrays
	printf("----------------------------------------------------------\n");
	printf("              Parallel Arrays \n");
	printf("----------------------------------------------------------\n");
	for (int i=0; i<SIZE; i++) {
		printf(" %9s %2d %8d %8.2f %8.5f\n", 
			     " ", i+1, iArray[i],fArray[i], dArray[i]);
	}
	printf("----------------------------------------------------------\n");
	
	// printing the statistics
	printf(" %9s    %8d %8.2f %8.5f\n", " Minimum ", iMin, fMin, dMin);
	printf(" %9s    %8d %8.2f %8.5f\n", " Maximum ", iMax, fMax, dMax);
	printf(" %9s    %8d %8.2f %8.5f\n", " Total   ", iTotal, fTotal, dTotal);
	printf(" %9s    %8.2f %8.2f %8.5f\n", " Average ", avgInt, avgFloat, avgDouble);
	printf("----------------------------------------------------------\n");
	
	return 0;
}
