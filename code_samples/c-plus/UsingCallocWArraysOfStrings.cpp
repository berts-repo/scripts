#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 101

// Program Name: UsingCallocWArraysOfStrings.cpp
// Author: GT
// This program shows the use of calloc to create an array of strings
// in which every string has different size,


/* Program that creates a dynamically allocated array */
int main(void) {
	int n = -1;                 // Size of an array, to be read from user
	char answer[MAXSIZE] = "Hi";  // String for user answers
    char **pets ;               // Pointer to an array of pointers to pointers

	/* Reading array size */
	while (n<=0) {
		printf(" How many kinds of pets can you name?: (>0)");
		scanf("%d", &n);
	}

	/* Creating Dynamically Allocated array of pointers to char */
    pets = (char **)calloc(n, sizeof(char *));
	if (pets != NULL) {
		/* Initiallizing Dynamically Allocated array of Records */
		for (int i = 0; i < n; i++) {
			printf(" Give me your kind of pet number %d: ", (i+1));
			scanf("%100s", answer);
			*(pets + i) = (char *)calloc(strlen(answer) + 1, sizeof(char));
			if (*(pets + i) != NULL) {
				strcpy(*(pets + i), answer);
			}
		}

		/* Printing Dynamically Allocated array of structures */
		printf( "\nYou mentioned:\n\n");
		for (int i = 0; i<n; i++) {
			printf("%d. %s (size=%zu)\n", i, (*(pets + i)), strlen(*(pets+i)));
		}

		// Returning memory before the end of the program

		// Returning memory for each element of the array
		for (int i = 0; i<n; i++) {
			free(*(pets + i));
		}
		// Returning memory for the array itself
		free(pets);

	}

	return 0;
} // end of main

