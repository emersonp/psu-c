// Copyright (c) 2014 Parker Harris Emerson
// Lab 2-3 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Write a C program to sort an array of n positive integers in ascending order using selection sort and print them out. Your program should read its input from a file named “data1.txt”. The first element in the file is a positive integer denoting “n”, the number of elements in the list to be sorted, followed by a blank line, and followed by a list of n positive integers separated by blanks.

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
    int* numArr = NULL;
    int lowIndex = 0;
    int tempHolder = 0;
    
    // Open file.
    FILE* fileHandle = fopen("Data1.txt", "r");
    {
        fscanf(fileHandle, "%d", &firstNum);
        numArr = (int*)(malloc(sizeof(int) * firstNum));
        for (int i = 0; i < firstNum; i++) {
            fscanf(fileHandle, "%d", &numArr[i]);
        }
    }
    // Super duper important - close the file.
    fclose(fileHandle);

    // Selection sort.
    printf("\n");
    for (int i = 0; i < firstNum; i++) {
        lowIndex = numArr[i];
        for (int j = i + 1; j < firstNum; j++) {
            if (lowIndex > numArr[j]) {
                tempHolder = lowIndex;
                lowIndex = numArr[j];
                numArr[j] = tempHolder;
            }
        }
        numArr[i] = lowIndex;
        printf("%d ", numArr[i]);
    }
    printf("\n");

    return 0;
}
