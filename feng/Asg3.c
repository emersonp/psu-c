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
    if (!(argv[1] && argv[2] && argv[3])) {
        printf("\n\nUsage: Asg3.o <# of frac_bits> <# of exp_bits> <hex_to_convert>\n\n");
        exit(0);
    }
    
    // Declare some variables.
    int inputHex;
    sscanf(argv[3], "%x", &inputHex);
    int fractionSize = atoi(argv[1]);
    int fractionInt = 0;
    float significand;
    float fraction = 0;
    int exponentSize = atoi(argv[2]);
    int exponent = 0;
    int bias = pow(2, (exponentSize - 1)) - 1;
    int characteristic;
    int maskVar = 0;
    float output = 0;
    int normalized = 1;
    int signedBit = 0;

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
    fractionInt = (inputHex & maskVar);
    for (int i = 1; i <= fractionSize; i++) {
        if (fractionInt & 1 << (fractionSize - i)) {
            fraction += pow(2, -i);
        }
    }
    
    // Signed bit.
    signedBit = (inputHex & 1 << (fractionSize + exponentSize));
    if (signedBit) {
        signedBit = 1;
    }


    // Create significand.
    significand = 0;
    if (normalized) {
        significand = 1 + fraction;
    } else {
        significand = fraction;
    }

    // Reset and recreate maskVar.
    maskVar = 0;
    for (int i = 0; i < exponentSize; i++) {
        maskVar = (maskVar | 1 << i);
    }
    maskVar = maskVar << fractionSize;

    // Create exponent.
    exponent = (inputHex & maskVar);
    exponent = exponent >> fractionSize;
    if (normalized) {
        characteristic = exponent - bias;
    } else {
        characteristic = 1 - bias;
    }

    // Check normalization, NaN, infinity.
    if (!exponent) {
        printf("\nExponent: %d\n", exponent);
        normalized = 0;
    }
    if (!~exponent) {
        if (!fraction) {
            if (signedBit) {
                printf("-Infinity.\n\n");
                exit(0);
            } else {
                printf("+Infinity.\n\n");
                exit(0);
            }
        } else {
            printf("NaN.\n\n");
            exit(0);
        }
    }
    // Create and print the Output of Formula
    output = (significand * pow(2, characteristic));
    if (signedBit) {
        output = -output;
    }
    printf("\nThe total of your input is %f.\n\n\n", output);

    // Print debugging, left here in case Parker wants to fiddle with the program in the future.
    /*
      printf("inputHex: %d\n", inputHex);
      printf("significand: %f\n", significand);
      printf("exponent (without bias): %d\n", exponent);
      printf("characteristic (exponent): %d\n", characteristic);
      printf("bias: %d\n", bias);
      printf("fractionInt: %d\n", fractionInt);
      printf("signedBit: %d\n", signedBit);
    */ 

}    

