#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 20
#define n 5


// Program Name: UsingMallocWArraysOfStrings.cpp
// Author: GT
// This program shows the use of malloc to create an array of strings
// in which every string has different size.


/* Program that creates a dynamically allocated array */
int main(void) {
	// Array of continents names with fixed size for Strings (MAXSIZE)
	char fixedName[n][MAXSIZE] = { "Africa", "America", "Asia", "Europa", "Oceania"} ;
	// Array of continents names with variable size for Strings
    char * varName[n] ;     // It is an array of Pointers to char to hold continents names

	/* Creating Dynamically Allocated elements of varName */
	for (int i = 0; i < n; i++) {
		varName[i] = (char *)malloc((strlen(fixedName[i]) + 1) * sizeof(char));
		if (varName[i] != NULL) {
			strcpy(varName[i], fixedName[i]);
		}
	}

	/* Printing Dynamically Allocated array of structures */
	for (int i = 0; i<n; i++) {
		printf("varName[%d]= %s (length=%zu)\n", i, varName[i], strlen(varName[i]));
	}

	// Returning memory for each element of the array before the end of the program
	for (int i = 0; i<n; i++) {
		free(varName[i]);
	}

	return 0;
} // end of main

