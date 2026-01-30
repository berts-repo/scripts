#include <stdio.h>
#include <string.h>
#define NCITIES 5
// Program Name: BiDimensionalArrays.cpp
// Author: GT
// Program to create an handle a bidimensional array of Numbers


int main(void)
{
	// A bidimensional array of city names
	char cityNames[NCITIES][4] = { "AUS", "NYC", "SFO", "MSY", "ORD"} ;

	 // A bidimensional array of costs to go from CITY to CITY
	double cost[NCITIES][NCITIES] = {
		                              {   0.0, 250.0, 350.0, 150.0, 200.0 },
		                              { 250.0,   0.0, 450.0, 200.0, 210.0 },
		                              { 350.0, 450.0,   0.0, 400.0, 420.0 },
		                              { 150.0, 200.0, 400.0,   0.0, 230.0 },
		                              { 200.0, 210.0, 420.0, 230.0,   0.0 }
	};

	char option[6] = "";    // Array with the name of a city option
	int selected = -1;		// selected city

	// Printing costs of moving from one city to another
	printf("Table of moving cost between cities\n");
	printf("%7s"," ");
	for (int i=0; i<NCITIES; i++) {
		printf("%7s",cityNames[i]);
	}

	for (int i=0; i<NCITIES; i++) {
		printf("\n%7s",cityNames[i]);
		for (int j=0; j<NCITIES; j++) {
			printf("%7.2f",cost[i][j]);
		}
	}
	printf("\n");

	printf("Select a city: ");
	scanf("%5s", option);
	selected = -1;
	for (int i = 0; i < NCITIES; i++) {
		if (strcmp(cityNames[i], option) == 0) {
			selected = i;
		}
	}

	if (selected < 0) {
		printf("%s is a wrong choice. Sorry! you lost the special offer.", option);
	}
	else {
		printf("Congratulations! you have discounts from %s to many cities. New Prices:\n", option);
		for (int i = 0; i<NCITIES; i++) {
			if (i != selected) {
				printf("%7s", cityNames[i]);
			}
		}
		printf("\n");
		for (int i = 0; i<NCITIES; i++) {
			if (i != selected) {
				printf("%7.2f", 0.9*cost[selected][i]);
			}
		}
	}
	printf("\n");

	return 0;
}
