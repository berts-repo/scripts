#include <stdio.h>
#include <string.h>
#define VALUES_PER_RECORD 8

// Program Name: UsingBinaryFile.cpp
// Author: GT
// This program shows how to use create, read and update a Binary file

// Function prototypes
int EnsureInputFile(char *filename);
int WriteBinaryFile(char *fIn, char*fBin);
int ReadBinaryFile(char *filename);
int UpdateBinaryFile(char *filename);

int main(void) {
	char fInName[] = "c-plus/Input5.txt";
	char fBinName[] = "c-plus/BinFile.bin";

	// Create a simple input file if it does not exist
	if (EnsureInputFile(fInName) != 0) {
		printf("There was an error creating file %s.\n", fInName);
		return -1;
	}

	// Creating Binary file froma an ASCII file
	if (WriteBinaryFile(fInName, fBinName) != 0) {
		printf("There was an error creating file %s.\n", fBinName);
		return -1;
	}

	// Reading Binary file
	if(ReadBinaryFile(fBinName) !=0) {
		printf("There was an error reading file %s.\n", fBinName);
		return -2;
	}

	// Updating Binary file
	if(UpdateBinaryFile(fBinName) !=0) {
		printf("There was an error updating file %s.\n", fBinName);
	}

	// Reading Binary file again to print it in the standard output
	if (ReadBinaryFile(fBinName) != 0) {
		printf("There was an error reading file %s.\n", fBinName);
		return -2;
	}

	return 0;
}

// This function creates a simple ASCII input file if it is missing
int EnsureInputFile(char *filename) {
	FILE *f = fopen(filename, "r");
	if (f != NULL) {
		fclose(f);
		return 0;
	}

	f = fopen(filename, "w");
	if (f == NULL) {
		return -1;
	}

	for (int i = 1; i <= 24; i++) {
		fprintf(f, "%d ", i);
	}
	fprintf(f, "\n");
	fclose(f);
	return 0;
}


// This function reads an ASCII file and creates a Binary file
int WriteBinaryFile(char *fIn, char*fBin) {
	FILE *fa;  // Pointer to a input ASCII file
	FILE *fb;  // Pointer to a binary file
	int record[VALUES_PER_RECORD];  // array with values in a record
	int i = 0; // Counter of the values in a line
	int ret = 0;  // return value;

	// Trying to open sequential ASCII input file
	fa = fopen(fIn,"r");
	if (fa == NULL) {
		printf("File %s was not found in current directory\n",fIn);
		return -1;
	}
	// Trying to open binary output file
	fb = fopen(fBin,"wb");
	if (fb == NULL) {
		printf("File %s could not be opened\n",fBin);
		return -1;
	}
	//Reading lines from the ASCII file and storing it in an array
	printf("Reading file %s. Writing file %s ... \n", fIn, fBin);
	while(fscanf(fa, "%d", &record[i]) >=1) {
		if (i==VALUES_PER_RECORD-1) {  // When all values in a line have been read
			for (int j=0;j<VALUES_PER_RECORD;j++) {   // Print the values on the screen
				printf("%d ",record[j]);
			}
			printf("\n");
			// Save the values of the record array in the FILE fb
			if(fwrite(record, sizeof(int), VALUES_PER_RECORD, fb)<VALUES_PER_RECORD){
					printf("Error wrtiting binary file %s\n",fIn);
			}
		}
		i++;
		i %= VALUES_PER_RECORD;
	}
	if (i>0) {  // This is in case there are records at then end of the input file
	            // with less than the number of values per record
		for (int j=i;j<VALUES_PER_RECORD;j++) { record[j]=0; }
		if(fwrite(record, sizeof(int), VALUES_PER_RECORD, fb)<VALUES_PER_RECORD){
					printf("Error wrtiting binary file %s\n",fIn);
		}
	}
	// Trying to close the ASCII input file
	if (fclose(fa) == EOF) {
		printf("There is an error at closing %s\n", fIn);
		ret = -2;
	}
	if (fclose(fb) == EOF) {
		printf("There is an error at closing %s\n", fBin);
		ret = -2;
	}
	return ret;
}

// This function reads a Binary file
int ReadBinaryFile(char*fBin) {
	FILE *fb;  // Pointer to a binary file
	int record[VALUES_PER_RECORD];  // array with values in a record

	// Trying to open binary output file
	fb = fopen(fBin,"rb");
	if (fb == NULL) {
		printf("File %s could not be opened\n",fBin);
		return -1;
	}
	//Reading binary file
	printf("Reading file %s... \n", fBin);
	while(fread(record, sizeof(int), VALUES_PER_RECORD, fb) == VALUES_PER_RECORD){
		for (int i=0;i<VALUES_PER_RECORD;i++) {
			printf("%d ",record[i]);
		}
		printf("\n");
	}
	// Trying to close the ASCII input file
	if (fclose(fb) == EOF) {
		printf("There is an error at closing %s\n", fBin);
		return -2;
	}
	return 0;
}

// This function Updates a Binary file
// It increments the last value on every row by one
int UpdateBinaryFile(char*fBin) {
	FILE *fb;    // Pointer to a binary file
	int value[1];  // array to receive the values read from the binary file
	int ok = 1;  // Status variable 0-> false 1-> true

	// Trying to open binary output file
	fb = fopen(fBin,"rb+");
	if (fb == NULL) {
		printf("File %s could not be opened\n",fBin);
		return -1;
	}
	//Reading and Updating Binary file
	printf("Updating file %s... \n", fBin);
	while ((ok==1) &&
		   (fseek(fb,7*sizeof(int),SEEK_CUR) == 0) &&
		   (fread(value, sizeof(int), 1, fb) == 1)) {
			value[0]+=10;
// Always have a fseek, fflush, fsetpos or rewind in between fread and fwrite
			if ((fseek(fb,-1L*sizeof(int),SEEK_CUR)!=0) ||
				(fwrite(value, sizeof(int), 1, fb) != 1)) {
				ok = 0;
			}
	}
	// Trying to close the Binary file
	if (fclose(fb) == EOF) {
		printf("There is an error at closing %s\n", fBin);
		return -2;
	}
	if (ok == 1) {
		return 0;
	}
	else {
		return -3;
	}
}
