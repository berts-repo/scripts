#include <stdio.h>

// Program Name: SentinelGrader.cpp
// Author: GT
// This program uses a indefinitive loop to calculate a grade average
// It uses the sentinel value of 0 and a while statement
// It also shows the use of multiple counter variables


int main(void)
{
	int grade_counter;  // Number of grades entered by the user
	int grade;          // Current grade value entered by the user
	float total;        // Sum of grades entered by the user
	float average;      // Average of grades entered
	int passed = 0;     // Number of passing grades

	// Initialization
	total = 0.0f;
	grade_counter = 0;

    // Reading of the first value from the user
	printf("Enter grade (negative value to quit): ");
	scanf("%d", &grade);

    // Loop to read and accumulate total
	while (grade >= 0) { // Sentinel is any negative value
		if (grade >= 60) {
			passed++;
		}
		total += grade;
		grade_counter++;
		// Reading of a next value to see if the loop continues
		printf("Enter grade (negative value to quit): ");
		scanf("%d", &grade);
	} // end for

	// calculating and displaying the average
	if (grade_counter > 0) {
		average = total / grade_counter;
		printf("\nTotal of all %d grades is %f\n", grade_counter, total);
		printf("Passing grades: %d Failed grades: %d\n", passed, (grade_counter - passed));
		printf("The grade average is %.2f\n", average);
	}
	else {
		printf("\nNo grades entered \n");
	} // end if
	return 0;
} // end main


