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

bool findIfBit(char *byte, int bit) {
    return (*byte & (1<<bit));
}

void onBit(char *byteSet, int bitSet) {
    *byteSet = (*byteSet | (1<<bitSet));
}

void offBit(char *byteSet, int bitSet) {
    *byteSet = (*byteSet & ~(1<<bitSet));
}

int main(int argc, char* argv[]) {
    
    // Declare some variables.
    long bufferSize = 0;
    char* inputBuffer;
    int inputIndex = 0;
    char* outputBuffer;
    int outputIndex = 0;
    char manipBuffer[5];
    int manipIndex = 0;
    char* fileToOpen;

    // Open the file. Get the data.
    fileToOpen = argv[1] ? argv[1] : "pemerson";
    FILE* fileHandle = fopen(fileToOpen, "r");
    {
        fseek(fileHandle, 0, SEEK_SET); // Seek to the start of the file.
        fseek(fileHandle, 0, SEEK_END); // Go to the end.
        bufferSize = ftell(fileHandle);
        fseek(fileHandle, SEEK_SET, 0); // Back to beginning.
        inputBuffer = (char*)(malloc(sizeof(char) * bufferSize));
        memset(inputBuffer, 0, bufferSize);
        outputBuffer = (char*)(malloc(sizeof(char) * bufferSize));
        memset(outputBuffer, 0, bufferSize);
        fread(inputBuffer, sizeof(char), bufferSize, fileHandle);
    }
    fclose(fileHandle);

    printf("%s\n", inputBuffer);

    //
    // Stage One
    //
    while (outputIndex < (bufferSize - 4)) {
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
    while (outputIndex < bufferSize) {
        outputBuffer[outputIndex++] = inputBuffer[inputIndex++];
    }
    
    //
    // Stage Two
    //
    for (int i = 0; i < bufferSize; i++) {
        if (outputBuffer[i] == 0) {
            continue;
        }
        int b2, b3, b4, b5;
        b2 = findIfBit(&outputBuffer[i], 2);
        b3 = findIfBit(&outputBuffer[i], 3);
        b4 = findIfBit(&outputBuffer[i], 4);
        b5 = findIfBit(&outputBuffer[i], 5);
        if (b2) {
            onBit(&outputBuffer[i], 4);
        } else {
            offBit(&outputBuffer[i], 4);
        }
        if (b4) {
            onBit(&outputBuffer[i], 2);
        } else {
            offBit(&outputBuffer[i], 2);
        }
        if (b5) {
            onBit(&outputBuffer[i], 3);
        } else {
            offBit(&outputBuffer[i], 3);
        }
        if (b3) {
            onBit(&outputBuffer[i], 5);
        } else {
            offBit(&outputBuffer[i], 5);
        }
    }

    //
    // Stage Three
    //

    for (int i = 0; i < bufferSize; i++) {
        if (i % 4 == 1 || i % 4 == 3) {
            outputBuffer[i] = (outputBuffer[i] ^ 'm');
        }
    }

    printf("%s\n", outputBuffer);

    return 0;
}    

