// Copyright (c) 2014 Parker Harris Emerson
// Lab 4 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.

// Given a graph G=(V,E), implement a depth-first search traversal of the graph. The output of your algorithm should be the graph G, with its vertices marked with consecutive positive integers in the order they are first encountered.
// Given a graph G=(V,E), implement a breadth-first search traversal of the graph. The output of your algorithm should be the graph G, with its vertices marked with consecutive positive integers in the order they are first encountered.
// The input file for both parts of this lab is named “Data7.txt”. The first element in the file is a positive integer (n) denoting the number of vertices in the graph, followed by a blank line, followed by an nxn matrix of 0’s and 1’s. This matrix is the adjacency matrix of the graph

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize and declare global variables.
int arraySize = 0;
int** graphArr = NULL;
int vertCount = 0;
int* queueArr = NULL;
int queuePop = 0;
int queuePush = 0;

void pushQueue(int pushVar) {
    queueArr[queuePush] = pushVar;
    if (queuePush == arraySize - 1) {
        queuePush = 0;
    } else {
        queuePush++;
    }
}

void popQueue() {
    queueArr[queuePop] = 0;
    if (queuePop == arraySize - 1) {
        queuePop = 0;
    } else {
        queuePop++;
    }
}

int isEmpty() {
    return (queuePop == queuePush);
}

void breadthFirst(int vertice) {
    vertCount++;
    graphArr[vertice][vertice] = vertCount;
    pushQueue(vertice);
    while (!isEmpty()) {
        for (int i = 0; i < arraySize; i++) {
            if (graphArr[i][queueArr[queuePop]] == 1 && graphArr[i][i] == 0) {
                vertCount++;
                graphArr[i][i] = vertCount;
                pushQueue(i);
            }
        }
        popQueue();
    }
}

void depthFirst(int vertice) {
    vertCount++;
    graphArr[vertice][vertice] = vertCount;
    for (int i = 0; i < arraySize; i++) {
        if (graphArr[i][vertice] == 1 && graphArr[i][i] == 0) {
            depthFirst(i);
        }
    }
}

void printArr() {
    for (int y = 0; y < arraySize; y++) {
        for (int x = 0; x < arraySize; x++) {
            printf("%d  ", graphArr[x][y]);
            if (graphArr[x][y] < 10) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    
    // Open file, assign to fileHandle
	FILE* fileHandle = fopen("./Data7.txt", "r");
	{
        // Create arrays.
        fscanf(fileHandle, "%d", &arraySize);
        graphArr = (int **)(malloc(sizeof(int *) * arraySize));
        queueArr = (int *)(malloc(sizeof(int) * arraySize));
        for (int i = 0; i < arraySize; i++) {
            graphArr[i] = (int *)(malloc(sizeof(int) * arraySize));
        }
        // Get all the data into arrays.
        for (int y = 0; y < arraySize; y++) {
            for (int x = 0; x < arraySize; x++) {
                fscanf(fileHandle, "%d", &graphArr[x][y]);
            }
        }
    }
    fclose(fileHandle);

    printf("\nInitial Input Array\n");
    printArr();
    // Set all visits to 0. Self-referencing vertices not important.
    for (int i = 0; i < arraySize; i++) {
        graphArr[i][i] = 0;
    }

    // Depth First
    for (int i = 0; i < arraySize; i++) {
        if (graphArr[i][i] == 0) {
            depthFirst(0);
        }
    }
    
    printf("\nDepth First Array\n");
    printArr();

    // Clear Visited
    for (int i = 0; i < arraySize; i++) {
        graphArr[i][i] = 0;
    }

    // Breadth First
    vertCount = 0;
    for (int i = 0; i < arraySize; i++) {
        if (graphArr[i][i] == 0) {
            breadthFirst(i);
        }
    }
    printf("\nBreadth First Array\n");
    printArr();


    return 0;
}
