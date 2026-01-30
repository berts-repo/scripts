#include <stdio.h>
#include <stdlib.h>

// Program Name: UsingRealloc.cpp
// Author: GT
// This program shows the use of realloc to modify previously allocated memory

int secondReAlloc(int **pOld, int nOld);

int main(void) {
	int n = 7;            // size of array
    int *pc = NULL;       // pointer to an array of integers
    int *pr = NULL ;      // pointer to reallocated array of integers
    int i;

	/* Creating an initial array using calloc */
	printf("Creating an array of %d integers\n\n",n);
	pc = (int *)calloc(n, sizeof(int));

	if (pc != NULL) {
		/* Initiallizing Array */
		for (i=0;i<n;i++) {
			pc[i] = 2 * i + 1 ;
		}

		/* Printing the initial array */
		printf("Initial array elements:\n\n");
		for (i = 0; i < n; i++) {
			printf("Array of int[%d]: %d\n", i, *(pc + i));
		}

		// Using realloc to reduce the size of the array
		n = n /2;
		printf("\nUsing realloc to halve the size of the array to %d integers\n\n",n);

		// a new pointer is used to avoid losing the original array, in case realloc fails
		pr = (int *)realloc(pc, n * sizeof(int));

		if (pr != NULL) {
			printf("Elements of the first reallocated array:\n\n");
			for (i = 0; i < n; i++) {
				printf("Array of int[%d]: %d\n", i, *(pr + i));
			}
			n = secondReAlloc(&pr,n);
			printf("Elements of the second reallocated array:\n\n");
			for (i = 0; i < n; i++) {
				printf("Array of int[%d]: %d\n", i, *(pr + i));
			}
			free(pr);
		}
		else {
			// If the reallocation fails, the original allocation with calloc
			// must be freed before the end of the program
			// Releasing the originla array, because reallocation fails
			printf("realloc to halve the size of the array failed.\n\n");
			free(pc);
		}
	}

	return 0;
}

// Function to Reallocate an array
// It receives the address to a pointer to a dynamic memory of integers and
// the original size of the array
// This function will try to triplicate the size of the original array
// It returns the new size of the array. The new array will be returned
// in the same address where the old array was. The old memory will be freed.
// if the functon cannot triplicate the array, the original array and size
// will be returned without any changeinstead.
int secondReAlloc(int **pOld, int nOld) {
	int n;
    int *pr = NULL ;      // pointer to reallocated array of integers

	if (pOld != NULL && *pOld != NULL) { // Checking if the pointers are not NULL
		n = 3*nOld;
		printf("\nUsing realloc to triplicate the size of the array to %d integers\n\n",n);

		// a new pointer is used to avoid losing the original array, in case realloc fails
		pr = (int *)realloc(*pOld, n * sizeof(int));

		if (pr != NULL) {
			// Initializing new memory:
			for (int i = nOld; i < n; i++) {
				*(pr + i) = 0;
			}
			// Replacing old address of the array
			// It does not need to be freed because realloc did it.
			*pOld = pr;
		}
		else {
			printf("realloc to triplicate the size of the array failed.\n\n");
			// Old memory is not freed, because it is still in use in main.
			// main will free it.
			n = nOld;
		}
	}
	return n;
}
