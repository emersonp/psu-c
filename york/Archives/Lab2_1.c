// Copyright (c) 2014 Parker Harris Emerson
// Lab 2-1 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Write a C program to compute the product of two nxn matrices and print the result. Your program should read data from a file named “data4.txt”. The first element in the file is a positive integer denoting the “n” the order of the matrices, followed by a blank line, followed by n rows of n integers, followed by a blank line, followed by n rows of n integers. The integers in each row are separated by blanks.

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	// Initialize and declare variables.
    int firstNum = 0;
    int* firstMatrix = NULL;
    int* secondMatrix = NULL;
    int* productMatrix = NULL;
    int cellProduct = 0;

    // Open file, assign to fileHandle
	FILE* fileHandle = fopen("./Data4.txt", "r");
	{
        fscanf(fileHandle, "%d", &firstNum);

        firstMatrix = (int*) (malloc(sizeof(int) * firstNum * firstNum));
        secondMatrix = (int*) (malloc(sizeof(int) * firstNum * firstNum));
        productMatrix = (int*) (malloc(sizeof(int) * firstNum * firstNum));

        for (int i = 0; i < (firstNum * firstNum); i++) {
            fscanf(fileHandle, "%d", &firstMatrix[i]);
        }
        for (int i = 0; i < (firstNum * firstNum); i++) {
            fscanf(fileHandle, "%d", &secondMatrix[i]);
        }

    }
    // Super important - close the file.
    fclose(fileHandle);

    // Product of matrices!
    for (int m = 0; m < firstNum; m++) {    
        for (int j = 0; j < firstNum; j++) {
            for (int k = 0; k < firstNum; k++) {
                cellProduct += firstMatrix[m * firstNum + j] * secondMatrix[j + firstNum * k];
            }
            productMatrix[m * firstNum + j] = cellProduct;
            cellProduct = 0;
        }
    }

    // Print the productMatrix
    for (int y = 0; y < firstNum; y++) {
        for (int x = 0; x < firstNum; x++) {
            printf("%d ", productMatrix[y * firstNum + x]);
        }
        printf("\n");
    }

    return 0;
}

// Question a: It matters only in that the cell of the resulting product matrix will be more or less (or even positive or negative, depending on the size).
// Question b: A dot product is just a one-dimensional matrix.
// Question c: I don't believe it would, since the scanf uses %d, which hunts for a digit, then hunts for another digit, scanning past the commas.
