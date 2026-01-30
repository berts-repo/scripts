//
//
// Bert Darnell
// 9/25/2022
//
// This program measures the idle time of the CPU,
// by making a reference to the linux "/proc/uptime" file,
// recording how long the system has been up, and how long it has been idle.
// The program then uses the recorded start/idle times, to measure how long it takes to
// to create an array of 100,000 random numbers between 1 and 1000,
// calculate the mean and standard deviation of these numbers, and
// then re-record the idle time from the "/proc/uptime" file.
//
//

#include <stdio.h>
#include <cstdlib>
#include <cmath>

#define SIZE 100000 

//
// Calculates the mean from the rand() array.
//

float calculateMean(float arr[SIZE])
{
	float mean, sum;

	for (int i = 0; i < SIZE; i++){
//		printf("%d: %d\n", i+1, arr[i]);
		sum += arr[i];
	}
	mean = sum / SIZE;
	return mean;
}

//
// Calculates and returns the standard deviation for the rand() array.
//

float calculateDev(float arr[SIZE], float mean)
{
	float StdDev, calcABS, calcDEV;
	for (int i = 0; i < SIZE; i++)	{
		calcABS = abs(arr[i] - mean);
		calcDEV += calcABS * calcABS;
	}
	StdDev = sqrt( calcDEV / SIZE);
	
	return StdDev;	
}

//
// Opens file "/proc/uptime" and reads and returns
// the system start and idle times, then closes file.
//

void openUptime(float* total,float* idle)
{
	FILE* uptime_file;

	uptime_file = fopen("/proc/uptime", "r");

	if (uptime_file == NULL)
	{
        	printf("Can't open.\n");
    	}
    	else
    	{
        	fscanf(uptime_file, "%f", total);
        	fscanf(uptime_file, "%f", idle);
        	fclose(uptime_file);
   	}
}

int main()
{
	float startTotalTime, endTotalTime, startIdleTime, endIdleTime;
	float standardDeviation, calculatedMean;
	float programTotalTime, programIdleTime, programWorkTime, percentage;
	float randNo[SIZE];
       	int rando[SIZE];
//
// Generates 100,000 numbers between 1 and 1000, then
// it takes the array of int and converts it to float.
//
	for (int i = 0; i < SIZE; i++){
		rando[i] = rand() % 1000 + 1;
	}
	for (int i = 0; i < SIZE; i++){
		randNo[i] = rando[i];
	}

//
// functions calls
//
	openUptime(&startTotalTime, &startIdleTime);
	calculatedMean = calculateMean(randNo);
	standardDeviation = calculateDev(randNo, calculatedMean);
	openUptime(&endTotalTime, &endIdleTime);
//
// Calculating the CPU uptime.
//
	programTotalTime = endTotalTime - startTotalTime;
	programIdleTime = endIdleTime - startIdleTime;
	programWorkTime = programTotalTime - programIdleTime;
	percentage = (programWorkTime / programTotalTime) * 100;
//
// Print format
//
	printf("Mean:            %.2f\n", calculatedMean);
	printf("StdDev:          %f\n", standardDeviation);
	printf("CPU start time:  %f  %f\n", startTotalTime, startIdleTime);
	printf("CPU end time:    %f  %f\n", endTotalTime, endIdleTime);
	printf("CPU uptime:      %.2f\n", percentage);

	return 0;
}
