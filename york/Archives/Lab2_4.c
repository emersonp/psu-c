// Copyright (c) 2014 Parker Harris Emerson
// Lab 2-4 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.

// Write a C program to sort an array of n positive integers in ascending order using bubble sort and print them out. Your program should read its input from a file named “data1.txt”. The first element in the file is a positive integer denoting “n”, the number of elements in the list to be sorted, followed by a blank line, followed by a list of n positive integers separated by blanks.

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
    for (int i = firstNum -1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (numArr[j] > numArr[j + 1]) {
                tempHolder = numArr[j + 1];
                numArr[j + 1] = numArr[j];
                numArr[j] = tempHolder;
            }
        }
    }
    for (int i = 0; i < firstNum; i++) {
        printf("%d ", numArr[i]);
    }
    printf("\n");

    return 0;
}

// Lab 2_3:
// real 0m0.013s
// user 0m0.013s
// sys  0m0.000s
// Lab 2_4:
// real 0m0.007s
// user 0m0.003s
// sys  0m0.003s
