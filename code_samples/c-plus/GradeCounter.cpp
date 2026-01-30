#include <stdio.h>

// Program Name: GradeCounter.cpp
// Author: GT
// This program uses a definitive loop to calculate a grade average
// It also shows the use of a while statement


int main(void)
{
	const int max_grades = 5; // Constant to limit the number of grades to 5
	int grade_counter;        // Number of grades entered by the user
	int grade;                // Current grade value entered by the user
	float total;              // Sum of grades entered by the user
	float average;            // Average of grades entered

	// Initialization
	total = 0.0f;
	grade_counter = 0;

	// Loop to read and accumulate total
	printf("You will be requested to enter %d values now.\n", max_grades);
	while (grade_counter < max_grades) {
		printf("Enter grade: ");
		scanf("%d", &grade);
		total += grade;
		grade_counter++;
	} // end of while
	// calculating and displaying the average
	average = total / max_grades;
	printf("\nTotal of all %d grades is %.2f\n", max_grades, total);
	printf("The grade average is %.2f\n", average);
	return 0;
} // end of main

// As an exercise, students may replace the constant maxGrades for a variable
// and request a number of grades to be procesed from the user to be used in the program.

