// Copyright (c) 2014 Parker Harris Emerson
// Lab 3-2 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.

// Given a set of n points in the plane, describe by their Cartesian coordinates, p i (x i , y i ). Using the Euclidean distance metric, find the two closest points in the set, using the brute force approach. The data is contained in the file named “data6.txt” and has the obvious format. Write a C program that does the computation and prints the indexes and the coordinates of the closest pair.

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int computeDistance(int xCoor1, int yCoor1, int xCoor2, int yCoor2);

int main(int argc, char* argv[]) {

    // Initialize and declare search variables.
    int numPairs = 0;
    int* intArrX = NULL;
    int* intArrY = NULL;
    double euclidDistance = 0;
    double minDistance = 0;
    int closePoints[4];

    // Open file, assign to fileHandle
	FILE* fileHandle = fopen("./Data6.txt", "r");
	{
    // Get all the data into arrays.
        fscanf(fileHandle, "%d", &numPairs);
        intArrX = (int*)(malloc(sizeof(int) * numPairs));
        intArrY = (int*)(malloc(sizeof(int) * numPairs));
        for (int i = 0; i < numPairs; i++) {
            fscanf(fileHandle, "%d%d", &intArrX[i], &intArrY[i]);
        }
    }
    // Super important - close the file!
    fclose(fileHandle);

    // Double loop (brute force) through the arrays, calcing the euclidian distance, and comparing to euclidDistance, tracking lowest.
    {
        for (int j = 0; j < numPairs; j++) {
            for (int k = j + 1; k < numPairs; k++) {
                euclidDistance = computeDistance(intArrX[j], intArrY[j], intArrX[k], intArrY[k]);
                (j == 0 && k == 1) ? minDistance = euclidDistance : 0; // If just starting off, set to something greater than 0.
                if (euclidDistance > 0 && euclidDistance <= minDistance) { // Gets the last closest pair in the list, but makes validation of first pair easier.
                    minDistance = euclidDistance;
                    closePoints[0] = intArrX[j];
                    closePoints[1] = intArrY[j];
                    closePoints[2] = intArrX[k];
                    closePoints[3] = intArrY[k];
                }
            }
        }
    }
    printf("The closest two points (or points tied for closest) are:\n(X, Y)\t(%d, %d)\n(X, Y)\t(%d, %d)\n", closePoints[0], closePoints[1], closePoints[2], closePoints[3]);
                
    return 0;
}

// computeDistance Function
int computeDistance(int xCoor1, int yCoor1, int xCoor2, int yCoor2) {
    int xSquare, ySquare;
    xSquare = (xCoor1 - xCoor2) * (xCoor1 - xCoor2);
    ySquare = (yCoor1 - yCoor2) * (yCoor1 - yCoor2);
    return sqrt(xSquare + ySquare);
}
    
