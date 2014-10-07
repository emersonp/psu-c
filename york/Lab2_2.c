// Copyright (c) 2014 Parker Harris Emerson
// Lab 2-2 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Write a C program to compute the number of binary digits in the representation of “n”, a positive decimal integer that will be entered at an input prompt of your program. Your program should print the number of binary digits.

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
    int inputInt = 0;
    int binaryDig = 0;

    printf("Please enter a number in decimal (base 10): ");
    scanf("%d", &inputInt);

    while (inputInt > 0) {
        inputInt /= 2;
        binaryDig++;
    }

    printf("\n\nWhen converted to binary, your number would be %d digits.\n", binaryDig);

    return 0;
}
