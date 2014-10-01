// Copyright (c) 2014 Parker Harris Emerson
// Lab 1-1 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Write a C program to sequentially search a list of positive integers read from a file named “data1.txt” for a positive integer read from the terminal. Your program should print the index or indexes of the position(s) in the list of positive integers at which the desired integer has been found. Use 0-origin indexing. If the desired integer cannot be found in the list, your program should print the string “NOT FOUND”

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

    // Get user integer.
    int userInt = 0;
    printf("Please enter a positive integer: ");
    scanf("%d", &userInt);
    printf("You entered positive integer: %d\n", userInt);

    // Initialize and declare search variables.
    int* intData = NULL;
	int intSize = 0;
    int foundUserInt = 0;

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
        if (userInt == intData[intFor1]) {
            printf("Number %d found at index %d.\n", userInt, intFor1);
            foundUserInt++;
        }
    }

    // If userInt not found, announce as such.
    if (!foundUserInt) {
        printf("Integer NOT FOUND.\n");
    }

}
