#include <stdio.h>
#include <string.h>
#define STRING_SIZE 100
#define STR_BUFF 99

// Program Name: String03.cpp
// Author: GT
// This program will show how find substrings, replace characters and compare C strings


int main(void)
{
	int ok=0;   // pseudo boolean that indicates if a string with vowels was entered
	char* index;  // pointer to string "XXX"
	char base1[STRING_SIZE]="\n";
	char base2[STRING_SIZE] = "bo-b-XXX\nBo-na-na, fan-na fo-fXXX,\nFee-fi-mo-mXXX\n";
	char stringIn[STRING_SIZE];         // user name
	char stringToUse[STRING_SIZE]="";      // name to use
	char stringOut[STRING_SIZE]="";		 // final text

	do {
		printf("\nEnter a name with a vowel and at least 3 letters before the end of the name:");
	    scanf("%20s", stringIn);

		// Checking it contains a vowel
		for (size_t i = 0; i < strlen(stringIn) && !ok; i++) {
			if ((stringIn[i] == 'a') || (stringIn[i] == 'A') ||
				(stringIn[i] == 'e') || (stringIn[i] == 'E') ||
				(stringIn[i] == 'i') || (stringIn[i] == 'I') ||
				(stringIn[i] == 'o') || (stringIn[i] == 'O') ||
				(stringIn[i] == 'u') || (stringIn[i] == 'U'))
			{
				strcpy(stringToUse, &stringIn[i]);
				ok = 1;
			}
		}
		if (!ok) {
			printf(" Sorry, we cannot rime this name! ... it has no vowels.\n");
		}
		else {
			if (strlen(stringToUse) < 3) {
				printf(" Sorry, we cannot rime this name! ... \n");
				printf(" ... the first vowel must appear at least 3 places before the end of the name.\n");
				strcpy(stringToUse, "");
				ok = 0;
			}
		}
	} while (!ok);

	strcat(base1, stringIn);
	strcat(base1, "!\n");
	strcat(base1, stringIn);
	strcat(base1, ", ");
	strcat(base1, stringIn);
	strcat(base1, ", ");

	index = strstr(base2, "XXX");
	memcpy(index,stringToUse,3);
	index = strstr(base2, "XXX");
	while (index != NULL) {
		memcpy(index,stringToUse,3);
		index = strstr(base2, "XXX");
	}

	strcat(stringOut, base1);
	strcat(stringOut, base2);
	strcat(stringOut, stringIn);
	strcat(stringOut, "\n");

	printf("%s\n",stringOut);

	return 0;
}

