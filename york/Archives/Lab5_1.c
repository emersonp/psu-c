// Copyright (c) 2014 Parker Harris Emerson
// Lab 5-1 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Given a positive integer, n, generate the binary reflected gray code of order n.

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int grayNum;

    do {
        if (argc == 2) {
            grayNum = atoi(argv[1]);
        } else {
            printf("Please enter a positive number to convert to grey code.\n");
            scanf("%d", &grayNum);
        }
    } while (grayNum < 1);

    printf("The gray number of %d is ", grayNum);

    grayNum = ((grayNum >> 1) ^ grayNum);
    int loop = 31;
    int oneEncountered = 0;

    while (loop >= 0) {
        if (grayNum & (1 << loop)) {
            oneEncountered = 1;
            printf("1");
        } else {
            if (oneEncountered) {
                printf("0");
            }
        }
        loop--;
    }
    printf("\n");

    return 0;
}
