// Copyright (c) 2014 Parker Harris Emerson
// Lab 1-3 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.

// Write a C program to determine if a list of 1000 positive integers read from a file named “data2.txt” contains any repeated elements. If it contains repeated elements, list the index and value of each repeated element. If it does not contain repeated elements, print the string “NO REPEATED ELEMENTS”.

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    // Initialize and declare search variables.
    int* intData = NULL;
    int* intAppeared = NULL;    
	int intSize = 0;
    int anyRepeats = 0;

    // Open file, assign to fileHandle
	FILE* fileHandle = fopen("./Data1.txt", "r");
	{
		// Grab first value, which declares number of integers in file.
        fscanf(fileHandle, "%d", &intSize);

		// Establish array intData, setting to size of first value.
        intData = (int*) (malloc(sizeof(int) * intSize));
        intAppeared = (int*) (malloc(sizeof(int) * intSize));
        memset(intAppeared, -1, intSize * sizeof(int));

		// Fill array with values, reading over file.
        for (int indexCounter_outer = 0; indexCounter_outer < intSize; indexCounter_outer++) {
			fscanf(fileHandle, "%d", &intData[indexCounter_outer]);
		}
	}
    
    // Super important - close the file.
	fclose(fileHandle);

    // Run through the array. If not -1, start nested loop through rest of the array. If inner and outer index equal, save value to intAppeared array, then set intData at inner index to -1 (to prevent further analysis).
    for (int indexCounter_outer = 0; indexCounter_outer < intSize; indexCounter_outer++) {
        if (intData[indexCounter_outer] != -1) {
            for (int indexCounter_inner = indexCounter_outer + 1; indexCounter_inner < intSize; indexCounter_inner++) {
                if (intData[indexCounter_outer] == intData[indexCounter_inner]) {
                    anyRepeats++;
                    intAppeared[indexCounter_outer] = intData[indexCounter_outer];
                    intAppeared[indexCounter_inner] = intData[indexCounter_inner];
                    intData[indexCounter_inner] = -1;
                }
            }
        }
    }

    // Run through intAppeared array. If value is not -1, then print value and its index.
    for (int indexCounter = 0; indexCounter < intSize; indexCounter++) {
        if (intAppeared[indexCounter] != -1) {
            printf("The value %d is repeated and appears at %d.\n", intAppeared[indexCounter], indexCounter);
        }
    }

    // If userInt not found, announce as such.
    if (!anyRepeats) {
        printf("NO REPEATS FOUND.\n");
    }

}
