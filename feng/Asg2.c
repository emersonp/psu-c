// Copyright (c) 2014 Parker Harris Emerson
// Assignment 2 for New Beginnings Fall 2014, Assigned by Wu-chang Feng.
// Write a program which "decrypts" a file from an "encryption" based on my username.

// Simon says: A complete list of includes.
#define _BSD_SOURCE
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char* argv[]) {
    
    // Declare some variables.
    char inputBuffer[50];
    int inputIndex = 0;
    char outputBuffer[50];
    int outputIndex = 0;
    char manipBuffer[5];
    int manipIndex = 0;
    char* fileToOpen;

    // Open the file.
    fileToOpen = argv[1] ? argv[1] : "file.txt";
    FILE* fileHandle = fopen(fileToOpen, "r");
    {
        fseek(fileHandle, SEEK_SET, 0); // Seek to the start of the file.
        fread(inputBuffer, sizeof(char), 50, fileHandle);
    }
    fclose(fileHandle);

    printf("%s\n", inputBuffer);

    // Stage One
    while (outputIndex < 48) {
        manipIndex = 0;
        manipBuffer[manipIndex++] = inputBuffer[inputIndex++];
        manipBuffer[manipIndex++] = inputBuffer[inputIndex++];
        manipBuffer[manipIndex++] = inputBuffer[inputIndex++];
        manipBuffer[manipIndex++] = inputBuffer[inputIndex++];
        outputBuffer[outputIndex++] = manipBuffer[0];
        outputBuffer[outputIndex++] = manipBuffer[3];
        outputBuffer[outputIndex++] = manipBuffer[2];
        outputBuffer[outputIndex++] = manipBuffer[1];
    }

    outputBuffer[49] = inputBuffer[49];
    outputBuffer[50] = inputBuffer[50];


    printf("%s\n", outputBuffer);

    return 0;
}    

