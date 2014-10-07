// Copyright (c) 2014 Parker Harris Emerson
// Lab 1-4 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.

// Write a C program to compute the dot product of two vectors. Your program should read from a file named “data3.txt”. The first value in the file is a positive integer denoting the number of components in each vector, followed by a blank line, followed by a list of integers, followed by a blank line, followed by another list of integers. Each list of integers has the same number of components. After computing the dot product, your program should print out its value.

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
	int intSize = 0;
    int* intArrX = NULL;
    int* intArrY = NULL;
    int dotProduct = 0;

    // Open file, assign to fileHandle
	FILE* fileHandle = fopen("./Data3.txt", "r");
	{
		// Grab first value, which declares number of integers in file.
        fscanf(fileHandle, "%d", &intSize);

		// Establish arrays intArrX and intArrY, setting to size of first value in data file.
        intArrX = (int*) (malloc(sizeof(int) * intSize));
        intArrY = (int*) (malloc(sizeof(int) * intSize));

		// Fill arrays with values, reading over file.
        for (int index = 0; index < intSize; index++) {
			fscanf(fileHandle, "%d", &intArrX[index]);
		}
        for (int index = 0; index < intSize; index++) {
            fscanf(fileHandle, "%d", &intArrY[index]);
        }
	}
    
    // Super important - close the file.
	fclose(fileHandle);

    // Run through both arrays, multiplying paired values, and add to dotProduct.
    for (int index = 0; index < intSize; index++) {
        dotProduct += (intArrY[index] * intArrX[index]);
    }

    // Print dotProduct
    printf("The dot product of %d vectors is %d.\n", intSize, dotProduct);
}

// Question 1: It "matters" if an integer is positive or negative only to the extent that you'll be adding a possibly negative (possible = !double negative) value, but no, you can add a vector going in the "other" direction to a dot product.

// Question 2: Nope. You could add together 100 3-dimensional vectors using the same methodology. 
