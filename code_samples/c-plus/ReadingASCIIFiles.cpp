#include <stdio.h>
#include <string.h>

// Program Name: ReadingASCIIFiles.cpp
// Author: GT
// This program shows how to use file commands to read ASCII files

// Function prototypes
int readFileWfgetc(char *filename);
int readFileWfgets(char *filename);
int readFileWfscanf(char *filename);

int main(void) {
	char filename1[] = "c-plus/Input1.txt";
	char filename2[] = "c-plus/Input2.txt";
	char filename3[] = "c-plus/Input3.txt";

	// Reading ASCII file character by character with getc
	if (readFileWfgetc(filename1) != 0) {
		printf("There was an error reading file %s\n",filename1);
	}
	// Reading ASCII file line by line with gets
	if(readFileWfgets(filename2) !=0) {
		printf("There was an error reading file %s\n",filename2);
	}
	// Reading a formatted ASCII file line by line with fscanf
	if(readFileWfscanf(filename3) !=0) {
		printf("There was an error reading file %s\n",filename3);
	}

	return 0;
}


// This function reads a file character by character
int readFileWfgetc(char *filename) {
	FILE *f;  // Pointer to a sequential ASCII input file
	int c;    // Auxiliar character to read the file

	// Trying to open sequential input file
	f = fopen(filename,"r");
	if (f == NULL) {
		printf("File %s was not found in current directory\n",filename);
		return -1;
	}
	//Reading characters from the file one by one and printing them to the screen
	printf("\nContents of file: %s\n", filename);
	c = fgetc(f);
	while (c != EOF) {
		printf("%c", c);
		c = fgetc(f);
	}
	printf("\n");

	// Trying to close the sequential input file
	if (fclose(f) == EOF) {
		printf("There is an error at closing\n");
		return -2;
	}
	return 0;

}


// This function reads a file line by line
// It assumes that a line is not longer than 1000 characters
int readFileWfgets(char *filename) {
    const int maxSize = 1001;       // Maximum size expected for a line
    FILE *f = NULL;                 // Pointer to a sequential ASCII input file
    char buffer[maxSize] = "";      // buffer to receive lines from the file
    char *p = NULL;                 // Auxiliar pointer to location of '\n' in string

	// Trying to open sequential input file
	f = fopen(filename,"r");
	if (f == NULL) {
		printf("File %s was not found in current directory\n",filename);
		return -1;
	}
	//Reading lines from the file one by one and printing them to the screen as they come
	printf("\nContents of file: %s\n", filename);
	while (fgets(buffer, sizeof(buffer), f) != NULL) {
		printf("%s",buffer);
	}
	printf("\n");

	// Trying to close the sequential input file
	if (fclose(f) == EOF) {
		printf("There is an error at closing\n");
		return -2;
	}

	// Trying to open sequential for second time
	f = fopen(filename,"r");
	if (f == NULL) {
		printf("File %s was not found in current directory\n",filename);
		return -1;
	}
	// Reading lines from the file one by one
	// stripping them of the '\n' character and printing them to screen
	printf("\nContents of file : %s (stripped of '\\n')\n", filename);
	while (fgets(buffer, sizeof(buffer), f) != NULL) {
		p = strchr(buffer, '\n');
		if (p) {
		      *p = '\0';
		}
		printf("[%s] (%d)\n",buffer, strlen(buffer));
	}
	printf("\n");

	// Trying to close the sequential input file
	if (fclose(f) == EOF) {
		printf("There is an error at closing\n");
		return -2;
	}
	return 0;
}



// This function reads a file line by line
// It assumes that a line is not longer than 1000 characters
int readFileWfscanf(char *filename) {
    FILE *f = NULL;                 // Pointer to a sequential ASCII input file

	const char HEADER[] = "%d %4s %1s %d %d %f %f";   // Reading format
	const char HEADER_TO_PRINT[] = "%2d %5s %2s %5d %5d %7.2f %7.2f\n";   // Reading format

    // data to be read per record
    int itemNo;        // item number
	int age;           // patient's age in years
	int weight;        // patient's weight in pounds
	float height;      //patients height in cm
	float measurement; // physical measurement 1
	char code[5];      // patient's code
    char sex[2];       // sex code

	// Trying to open sequential input file
	f = fopen(filename,"r");
	if (f == NULL) {
		printf("File %s was not found in current directory\n",filename);
		return -1;
	}
	//Reading lines from the file one by one and printing them to the screen as they come
	printf("\nContents of file: %s\n", filename);
	while (fscanf(f, HEADER, &itemNo, code, sex, &age, &weight, &height, &measurement) >=7) {
		printf(HEADER_TO_PRINT, itemNo, code, sex, age, weight, height, measurement);
	}
	printf("\n");

	// Trying to close the sequential input file
	if (fclose(f) == EOF) {
		printf("There is an error at closing\n");
		return -2;
	}
	return 0;
}
