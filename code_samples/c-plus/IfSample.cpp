#include <stdio.h>

// Program Name: IfSample.cpp
// Author: GT
// This program shows various uses of if statements
// by asking the user for a grade value and producing grade letters

int main(void)
{
	int grade; // User's grade

	// Read one grade; negative value exits immediately
	printf("Please enter an integer grade number (Use a negative number to quit) : ");
	scanf("%d", &grade);

	// 1. Single if statement
	if (grade >= 0) {
		// The previous is a single if-statement: it has no else
		// All other if statements in this program are embedded,
		// since they are inside this previous if statement

		// 2. If-else statement
		if (grade >= 60) {
			printf("Congratulations! You passed the class!\n");
		}
		else {
			printf("I am sorry. You did not pass the class!\n");
		}  // end of if (grade >= 60)

		// 3. Sequential if-else statements
		if (grade >=90) {
			printf("Your grade is an A.\n");
		}
		else if (grade >=80) {
			printf("Your grade is a B.\n");
		}
		else if (grade >=70) {
			printf("Your grade is a C.\n");
		}
		else if (grade >=60) {
			printf("Your grade is a D.\n");
		}
		else {
			printf("Your grade is an F.\n");
		} // end of if (grade >= 90)

		// This sequential if-else statement cannot be converted directly to a switch
		// because there are infinite numbers above 90 to make a case for a grade of A.
		printf("Thanks for checking your grade.\n");

	} // end of if (grade >= 0)

	printf("Bye now.\n");

	return 0;
} // end of main
