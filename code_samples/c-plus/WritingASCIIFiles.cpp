#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Program Name: WritingASCIIFiles.cpp
// Author: GT
// This program shows how to use file commands to write ASCII files

// Function prototypes
int writeFileWfputc(char *fInName, char *fOutName);
int writeFileWfputs(char *fInName, char *fOutName);
int writeFileWfprintf(char *fInName, char *fOutName);

int main(void) {
	char fileIn1[] = "c-plus/Input1.txt";
	char fileIn2[] = "c-plus/Input2.txt";
	char fileIn3[] = "c-plus/Input3.txt";
	char fileOut1[] = "c-plus/Output1.txt";
	char fileOut2[] = "c-plus/Output2.txt";
	char fileOut3[] = "c-plus/Output3.txt";

	// Writing ASCII file character by character with getc
	if (writeFileWfputc(fileIn1,fileOut1) != 0) {
		fprintf(stderr, "There was an error creating file %s\n",fileOut1);
	}
	// Writing ASCII file line by line with gets
	if(writeFileWfputs(fileIn2,fileOut2) !=0) {
		fprintf(stderr, "There was an error creating file %s\n",fileOut2);
	}
	// Writing a formatted ASCII file line by line with fscanf
	if (writeFileWfprintf(fileIn3, fileOut3) != 0) {
		fprintf(stderr, "There was an error creating file %s\n",fileOut3);
	}

	return 0;
}


// This function reads a file character by character
// and creates a second file with the characters in upper case
int writeFileWfputc(char *fInName, char *fOutName) {
	FILE *fi = NULL;  // Pointer to a sequential ASCII input file
	FILE *fo = NULL;  // Pointer to a sequential ASCII output file
	int c;   // Auxiliar character to read the file

	// Trying to open sequential input file
	fi = fopen(fInName,"r");
	if (fi == NULL) {
		fprintf(stderr, "File %s was not found in current directory\n",fInName);
		return -1;
	}
	// Trying to open sequential output file
	fo = fopen(fOutName,"w");
	if (fo == NULL) {
		fprintf(stderr, "File %s was not found in current directory\n",fOutName);
		return -3;
	}
	// Reading characters from input file one by one and
	// saving them as upper case in the output file
	printf("\nCreating file %s ...\n", fOutName);
	c = fgetc(fi);
	while (c != EOF) {
		fputc(toupper((unsigned char)c), fo);
		c = fgetc(fi);
	}
	printf("\n");

	// Trying to close the sequential input file
	if (fclose(fo) == EOF) {
		fprintf(stderr, "There is an error at closing %s\n", fOutName);
		return -2;
	}
	if (fclose(fi) == EOF) {
		fprintf(stderr, "There is an error at closing %s\n", fInName);
		return -2;
	}
	return 0;
}


// This function reads a file line by line
// and creates a second file with the characters in upper case
// It assumes that a line is not longer than 1000 characters
int writeFileWfputs(char *fInName, char *fOutName) {
    const int maxSize = 1001;       // Maximum size expected for a line
	FILE *fi = NULL;  // Pointer to a sequential ASCII input file
	FILE *fo = NULL;  // Pointer to a sequential ASCII output file
    char buffer[maxSize] = "";      // buffer to receive lines from the file
    char *p = NULL;                 // Auxiliar pointer to location of '\n' in string
    int fail = 0;                   // status indicator 0->false 1.> true

	// Trying to open sequential input file
	fi = fopen(fInName,"r");
	if (fi == NULL) {
		fprintf(stderr, "File %s was not found in current directory\n",fInName);
		return -1;
	}
	// Trying to open sequential output file
	fo = fopen(fOutName,"w");
	if (fo == NULL) {
		fprintf(stderr, "File %s was not found in current directory\n",fOutName);
		return -3;
	}
	// Reading lines from the file one by one and
	// saving them as upper case in the output file
	printf("\nCreating file %s ...\n", fOutName);
	while ((fgets(buffer, sizeof(buffer), fi) != NULL) && (fail !=1)) {
		for (int i=0;i<maxSize && buffer[i]!='\0';i++) {
			buffer[i] = toupper(buffer[i]);
		}
		if (fputs(buffer, fo)==EOF){
			fprintf(stderr, "Problem writing file %s.\n",fOutName);
			fail = 1;
		}
	}
	printf("\n");

	// Trying to close the sequential input file
	if (fclose(fo) == EOF) {
		fprintf(stderr, "There is an error at closing %s\n", fOutName);
		return -2;
	}
	if (fclose(fi) == EOF) {
		fprintf(stderr, "There is an error at closing %s\n", fInName);
		return -2;
	}
	return 0;
}



// This function reads a file line by line
//gt And creates a second output file with fields separated by commas (,)
int writeFileWfprintf(char *fInName, char *fOutName) {
    FILE *fi = NULL;      // Pointer to a sequential ASCII input file
	FILE *fo = NULL;       // Pointer to a sequential ASCII output file

	const char HEADER[] = "%d %4s %1s %d %d %f %f";   // Reading format
	const char HEADER_TO_PRINT[] = "%2d, %5s, %2s, %5d, %5d, %7.2f, %7.2f\n";   // Reading format

    // data to be read per record
    int itemNo;        // item number
	int age;           // patient's age in years
	int weight;        // patient's weight in pounds
	float height;      //patients height in cm
	float measurement; // physical measurement 1
	char code[5];      // patient's code
    char sex[2];       // sex code

	// Trying to open sequential input file
	fi = fopen(fInName,"r");
	if (fi == NULL) {
		fprintf(stderr, "File %s was not found in current directory\n",fInName);
		return -1;
	}
	// Trying to open sequential output file
	fo = fopen(fOutName,"w");
	if (fo == NULL) {
		fprintf(stderr, "File %s was not found in current directory\n",fOutName);
		return -3;
	}
	// Reading contents of lines from the file with a format and
	// saving them in the output file
	printf("\nCreating file %s ...\n", fOutName);
	while (fscanf(fi, HEADER, &itemNo, code, sex, &age, &weight, &height, &measurement) >=7) {
		fprintf(fo, HEADER_TO_PRINT, itemNo, code, sex, age, weight, height, measurement);
	}

	// Trying to close the sequential input file
	if (fclose(fo) == EOF) {
		fprintf(stderr, "There is an error at closing %s\n", fOutName);
		return -2;
	}
	if (fclose(fi) == EOF) {
		fprintf(stderr, "There is an error at closing %s\n", fInName);
		return -2;
	}
	return 0;
}
