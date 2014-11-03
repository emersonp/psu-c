// Copyright (c) 2014 Parker Harris Emerson
// Lab 5-1 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Given an array of n elements, A[0, ... , n − 1] sorted in ascending order and a search key, K, perform a non-recursive binary search. Output the index of the array’s element that is equal to K or -1 if there is no such element. The input file for your C program is named “data8.txt” and it has the same format as “data1.txt”. You should test your code with various elements from the list (eg 1910, 9218, 24459) as well as elements not on the list (eg. 1895, 14416).

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int arraySize = 0;
    int* searchArray = NULL;
    int searchNum = 0;
    int splitNum = 0, lowBound = 0, highBound = 0;

    if (argc == 2) {
        searchNum = atoi(argv[1]);
    } else {
        printf("Please enter a number to search for.\n");
        scanf("%d", &searchNum);
    }
    
    // Open file, assign to fileHandle
	FILE* fileHandle = fopen("./Data8.txt", "r");
	{
        // Create array.
        fscanf(fileHandle, "%d", &arraySize);
        searchArray = (int *)(malloc(sizeof(int) * arraySize));
        for (int i = 0; i < arraySize; i++) {
            fscanf(fileHandle, "%d", &searchArray[i]);
        }
    }
    fclose(fileHandle);

    highBound = arraySize - 1;

    // Perform non-recursive binary search
    do {
        splitNum = (lowBound + highBound) / 2;
        // printf("lowBound: %d\nhighBound: %d\nsplitNum: %d\nsearchArray: %d\n\n", lowBound, highBound, splitNum, searchArray[splitNum]);
        if (searchNum < searchArray[splitNum]) {
            highBound = splitNum - 1;
        } else if (searchNum > searchArray[splitNum]) {
            lowBound = splitNum + 1;
        } else {
            printf("Number found at index %d.\n", splitNum);
            break;
        }
    } while (lowBound <= highBound);
    if (searchNum != searchArray[splitNum]) {
        printf("Number not found.\n");
    }

    return 0;
}
