#include <stdio.h>
#include <stdlib.h>

// Program Name: UsingMalloc.cpp
// Author: GT
// This program shows the use of malloc to create arrays

int main(void) {
	int n = -1;            // size of an array, to be read from user
    int *pi = NULL;        // pointer to an array of integers
    float *pf = NULL ;     // pointer to an array of floats
    int i;

	/* Reading array size */
	while (n<=0) {
		printf(" please provide an array size: (>0)");
		scanf("%d", &n);
	}

	/* Creating Dynamically Allocated arrays using malloc */
    pi = (int *)malloc(n * sizeof(int));
    pf = (float *)malloc(n * sizeof(float));

    if (pi != NULL) {
		/* Initiallizing Dynamically Allocated Array of ints */
		for (i=0;i<n;i++) {
			pi[i] = 2 * i ;
			//Alternatively we could use:
			// *(pi+i) = 2 * i ;
		}

		/* Printing the array */
		printf("Array of integers\n\n");
		for (i = 0; i < n; i++) {
			printf("Array of int[%d]: %d\n", i, *(pi + i));
			// Alternatively we could use:
			// printf"Array of int[%d]: %d\n", i, pi[i]) ;
		}

		// Returning memory when is no longer needed before the end of the program
		free(pi);
	}// end of if

    if (pf != NULL) {
		/* Initiallizing Dynamically Allocated Array of floats */
		for (i=0;i<n;i++) {
			*(pf+i) = 2.0f * i + 1.0f/(i+1.0f) ;
			//Alternatively we could use:
			// pf[i] = 2.0f * i + 1.0f/(i+1.0f) ;
		}

		/* Printing the array */
		printf("\nArray of floats\n\n");
		for (i=0;i<n;i++) {
			printf("Array of float[%d]: %f\n", i, pf[i]) ;
			// Alternatively we could use:
			// printf"Array of float[%d]: %d\n", i, *(pf+i)) ;
		}

		// Returning memory when is no longer needed before the end of the program
		free(pf);
	}  // end of if


	return 0;
} //end of main
