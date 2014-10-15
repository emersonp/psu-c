// Copyright (c) 2014 Parker Harris Emerson
// Assignment 3 for New Beginnings Fall 2014, Assigned by Wu-chang Feng.

// Implement an IEEE floating point parser for an arbitrary number of bit settings

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

int main(int argc, char *argv[]) {

    // Instructions for use:
    printf("\n\nUsage: Asg3.o <# of frac_bits> <# of exp_bits> <hex_to_convert>\n\n");
    if (!(argv[1] && argv[2] && argv[3])) {
        printf("\nPlease pass in three arguments in the format [int][int][hex].\n");
        exit(0);
    }
    
    // Declare some variables.
    int inputSign = 0;
    int inputHex;
    sscanf(argv[3], "%x", &inputHex);
    int fractionSize = atoi(argv[1]);
    int exponentSize = atoi(argv[2]);
    int bias = pow(2, (exponentSize - 1)) - 1;
    int maskVar = 0;
    float fraction = 0;
    int normalized = 1;

    // Test input arguments.
    if (fractionSize < 2 || fractionSize > 10) {
        printf("argv[1]: %d\nIllegal number of fraction bits. Should be between 2 and 10.\n", fractionSize);
        exit(0);
    }
    if (exponentSize < 3 || exponentSize > 5) {
        printf("Illegal number of exponent bits. Should be between 2 and 10.\n");
    }

    // Create maskVar
    for (int i = 0; i < fractionSize; i++) {
        maskVar = (maskVar | 1 << i);
    }

    // Create fraction.
    int fractionInt = (inputHex & maskVar);
    for (int i = 1; i <= fractionSize; i++) {
        if (fractionInt & 1 << (fractionSize - i)) {
            fraction += pow(2, -i);
        }
    }
    
    // Reset and recreate maskVar.
    maskVar = 0;
    for (int i = 0; i < exponentSize; i++) {
        maskVar = (maskVar | 1 << i);
    }
    maskVar = maskVar << fractionSize;

    // Create exponent.
    int exponent = (inputHex & maskVar);
    exponent = exponent >> fractionSize;
    exponent -= bias;

    // Signed bit.
    int signedBit = (inputHex & 1 << (fractionSize + exponentSize));
    if (signedBit) {
        signedBit = 1;
    }

    // Create mantissa.
    float mantissa = 0;
    if (normalized) {
        mantissa = 1 + fraction;
    }
    printf("mantissa: %f\n", mantissa);

    // Create and print the Output of Formula
    float output = (mantissa * pow(2, exponent));
    if (signedBit) {
        output = -output;
    }
    printf("The total of your input is %f.\n", output);

    // Print
    printf("inputHex: %d\n", inputHex);
    printf("exponent: %d\n", exponent);
    printf("bias: %d\n", bias);
    printf("fractionInt: %d\n", fractionInt);
    printf("signedBit: %d\n", signedBit);

}    

