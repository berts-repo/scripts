#include <stdio.h>
#include <stdlib.h>

// Program Name: CreatingArrayInFunction.cpp
// Author: GT
// This program shows how to properly create arrays  inside functions

// Function that creates an array and returns it inside a parameter
int createArray1 (int **a, int size) {
	if ((a!=NULL)&&(size>0)) {
		*a = (int *)calloc(size, sizeof(int));
		if (*a == NULL) {
			printf("Array could not be created.\n");
			return -1;
		}
		return 0;
	}
	else {
		printf("Array cannot be created. Null values received.\n");
		return -2;
	}
}

// Function that creates an array and returns it inside a parameter
int* createArray2 (int size) {
	int *a;
	if (size>0) {
		a = (int *)calloc(size, sizeof(int));
		if (a == NULL) {
			printf("Array could not be created.\n");
			return NULL;
		}
		return a;
	}
	else {
		printf("Array cannot be created. Null values received.\n");
		return NULL;
	}
}

int main(void) {
	int *pA = NULL;  // Pointer to array A
	int *pB = NULL;  // Pointer to array B
	int n = 10;      // Size of arrays

	// Creating arrayA passing its address as a parameter
	if (createArray1(&pA,n) == 0) {
		/* Initiallizing Dynamically Allocated Array of ints */
		for (int i=0;i<n;i++) {
			*(pA+i) = 2 * i + 1;
		}

		/* Printing the array */
		printf("First Array of integers\n\n");
		for (int i = 0; i < n; i++) {
			printf("Array of int[%d]: %d\n", i, *(pA+i));
		}

		// Returning memory when is no longer needed before the end of the program
		free(pA);
	}

	// Obtaining arrayB from createArray2
	pB = createArray2(n);
	if (pB != NULL) {
		// Initiallizing Dynamically Allocated Array of ints 
		for (int i=0;i<n;i++) {
			*(pB+i) = 2 * i;
		}

		// Printing the array 
		printf("Second Array of integers\n\n");
		for (int i = 0; i < n; i++) {
			printf("Array of int[%d]: %d\n", i, *(pB+i));
		}

		// Returning memory when is no longer needed before the end of the program
		free(pB);
	}
	return 0;
}
