#include <stdio.h>
#include <string.h>

// Program Name: String02.cpp
// Author: GT
// This program will show how to compare C strings


int main(void)
{
	// Arrays of characters to show strings C
	char s1[] = "cat";
	char s2[] = "dog";
	char s3[] = "lion";
	char answer[10];

    // integer valuables to store comparison variables
	int comparison1;
	int comparison2;
	int comparison3;

	printf(" Animal List\n");
	printf("1. string1: %s\n",s1);
    printf("2. string2: %s\n",s2);
	printf("3. string3: %s\n", s3);

    //comparing using conditional expressions
	printf("Write the name from the list of animals above: ");
	scanf("%9s", answer);
	printf("Answer=[%s]\n", answer);

	if (strcmp(answer,s1) == 0) {
		printf(" You chose the first option.\n");
	}
	else if (strcmp(answer,s2) == 0) {
		printf(" You chose the second option.\n");
	}
	else if (strcmp(answer,s3) == 0) {
		printf(" You chose the third option.\n");
	}
	else {
		printf(" You did not chose any of the above.\n");
	}

	printf(" Enter the name of another animal not in the list:\n");
	scanf("%9s", answer);

	comparison1 = strcmp(answer,s1);
	comparison2 = strcmp(answer,s2);
	comparison3 = strcmp(answer,s3);

	if (comparison1 < 0) {
			printf(" %s is before %s.\n", answer, s1);
    }
    else if (comparison1 == 0) {
			printf(" This animal is %s.\n",s1);
	}
    else if ((comparison1 > 0) && (comparison2 <0)){
			printf(" %s is between %s and %s.\n", answer, s1, s2);
	}
    else if (comparison2 == 0) {
			printf(" This animal is %s.\n",s2);
	}
    else if ((comparison2 > 0) && (comparison3 <0)){
			printf(" %s is between %s and %s.\n", answer, s2, s3);
	}
    else if (comparison3 == 0) {
			printf(" This animal is %s.\n",s3);
	}
	else {
			printf(" %s is after %s.\n", answer, s3);
	}

	return 0;
}

