#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Program Name: UsingCallocWStructures.cpp
// Author: GT
// This program shows the use of calloc to create a array of structures

struct myStruct {                     // definition of the structure
	int number;
	double income;
};
typedef struct myStruct Record;     //creating a nickname for the structure

void multiplyBy2(Record * p, int n);
void badCreateNew(Record * p);
int createNew(Record ** p);
void printArray(Record *p, int n);

/* Program that creates a dynamically allocated array */
int main(void) {
	int n = -1;            // Size of an array, to be read from user
	int n1;                // New size of array receied from function createNew
    Record *p ;            // pointer to array of Record (struct myStruct)

	/* Reading array size */
	while (n<=0) {
		printf(" please provide an array size: (>0)");
		scanf("%d", &n);
	}

	/* Creating Dynamically Allocated array */
    p = (Record *)calloc(n, sizeof(Record));

	if (p != NULL) {
		/* Initiallizing Dynamically Allocated array of Records */
		for (int i = 0; i < n; i++) {
			(p+i)->number = (i+1);
			(*(p+i)).income = 100.0 * (i+1);
		}

		/* Printing Dynamically Allocated array of structures */
		printf( "\nOriginal array\n\n");
		printArray(p, n);

		/* Calling multiplyBy2 function*/
		multiplyBy2(p, n);

		/* Printing Dynamically Allocated array after doubling */
		printf("\nArray after multiply by 2\n");
		printArray(p, n);

		/* Calling badCreateNew that tries to replace the array of structures */
		badCreateNew(p);

		/* Printing Dynamically Allocated array after badCreateNew */
		printf("\nArray after badCreateNew\n\n");
		printArray(p, n);

		/* Calling createNew function*/
		// n1 receives the new size of the array
		n1 = createNew(&p);
		if (n1>0) {	n = n1;	}

		/* Printing Dynamically Allocated array after createNew */
		printf("\nArray after createNew\n\n");
		printArray(p,n);

		// Returning memory before the end of the program
		free(p);

	}

	return 0;
} // end of main


/* function to double the income of every employee in an array of Record*/
void multiplyBy2(Record * p, int n) {
	if (p != NULL) {  // Always check if a received pointer is not NULL
		for (int i = 0; i < n; i++) {
			(*(p + i)).income *=2.0;
		}
	}

}
// Bad function: Tries to create a new array of structures, but it does not work
void badCreateNew(Record * p) {
	Record *oldP = NULL;    // pointer to old array

	if (p != NULL) {  // Always check if a received pointer is not NULL
		oldP = p;      // Saving the old address of the array to free its memory if changed
		p = (Record *)calloc(1, sizeof(Record)); // This is a local array and
												 // it will not affect the array in main
		if (p != NULL) {  // Always check if the call to calloc was succesful
			p->number = 10;
			(*p).income = 12345.0;
			/* Printing Dynamically Allocated array inside badCreateNew */
			printf("\nArray created inside badCreateNew\n\n");
			printArray(p,1);
			// Under normal circumstances the previous memory allocated to p
			// should be freed before the function ends because it is not going
			// to be used elsewhere. We would use: free(oldP);
			// However, we do not free the memory because you will see that
			// the function could not change the array in main.
		}
		else {
			printf("There was a problem and new array was not created\n");
			p = oldP;
		}

		// The memory in this function should also be freed, but this is not done
		// for you to see that it does not affect the array in main
	}
}

// Function that correctly creates a new array of structures and returns it.
// The key is that the address of the address of the array in main is the parameter
// therefore we can change the address of the arry in main.
// The function returns the number of records in the new arrays
int createNew(Record ** p) {
	Record *oldP = NULL;    // pointer to old array

	if (p != NULL) {  // Always check if a received pointer is not NULL
		oldP = *p;      // Saving the old address of the array to free its memory if changed
		*p = (Record *)calloc(1, sizeof(Record)); // This is changing the array in main
		if (*p != NULL) {    // Always check if the call to calloc was succesful
			(*p)->number = 10;
			(**p).income = 12345.0;
			free(oldP);      // freeing old memory after new one is successfully allocated
			return 1;
		}
		else {
			*p = oldP;  // restauring the old array, because the new one could not be created
		}
	}
	return 0;  // returning zero because there was a problem.
}

// Function to print the contents of the array of structures
void printArray(Record *p, int n) {
	if (p != NULL) { // Always check if a received pointer is not NULL
		for (int i = 0; i<n; i++) {
			printf("Array[%d]: (%d, %f)\n", i, (*(p + i)).number, (p + i)->income);
		}
	}
}
