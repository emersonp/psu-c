// Copyright (c) 2014 Parker Harris Emerson
// Lab 1-1 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Write a C program to find and print to the terminal the largest element in a list of positive integers that are read from a file named “data1.txt”.

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A friendly reminder for file compilation.
// use gcc -Wall -std=c99 -g inputfilename.c -o -outputfilename.o -lm

int main(int argc, char* argv[]) {
	// Initialize and declare variables.
    int* intData = NULL;
	int intScan = 0;
	int intSize = 0;

    // Open file, assign to fileHandle
	FILE* fileHandle = fopen("./Data1.txt", "r");
	{
		// Grab first value, which declares number of integers in file.
        fscanf(fileHandle, "%d", &intSize);

		// Establish array intData, setting to size of first value.
        intData = (int*) (malloc(sizeof(int) * intSize));

		// Fill array with values, reading over file.
        for (int intFor1 = 0; intFor1 < intSize; intFor1++) {
			fscanf(fileHandle, "%d", &intData[intFor1]);
		}
	}
    
    // Super important - close the file.
	fclose(fileHandle);

	// Run through the array, comparing to intScan (initially declared at 0), and tracking largest.
    for (int intFor1 = 0; intFor1 < intSize; intFor1++) {
        if (intData[intFor1] > intScan) {
            intScan = intData[intFor1];
        }
    }

    printf("The largest number in the file is %d.\n", intScan);
	
    // Free up the data in the array.
    free(intData);
}
