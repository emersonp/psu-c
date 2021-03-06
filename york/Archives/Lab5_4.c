// Copyright (c) 2014 Parker Harris Emerson
// Lab 5-4 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Compute the function f(n) = a n , for some a ≠ 0 and n an integer ≥ 0, using an algorithm that utilizes the decrease by a constant method. Your C program should accept two values as input, a and n. In the first version, both a and n should be positive integers. In the second version, let a be a non-zero floating point number and let n be a positive integer. Make the third version the same as the second version, except that n may be a negative integer. 

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float toPower(float baseNum, int exponentNum) {
    if (exponentNum == 1) {
        return baseNum;
    } else if (exponentNum == -1) {
        return 1 / baseNum;
    } else if (exponentNum > 0 && exponentNum % 2 == 0) {
        return pow(toPower(baseNum, exponentNum / 2), 2);
    } else if (exponentNum > 0 && exponentNum > 1 && exponentNum % 2 == 1) {
        return baseNum * pow(toPower(baseNum, (exponentNum - 1) / 2), 2);
    } else if (exponentNum < 0 && exponentNum % 2 == -0) {
        printf("We get here (even)\n");
        return toPower(baseNum, exponentNum / 2) / baseNum;
    } else if (exponentNum < 1 && exponentNum % 2 == -1) {
        printf("We get here (odd)\t%d\n", exponentNum);
        return toPower(baseNum, (exponentNum - 1) / 2) / baseNum;
    } else if (exponentNum == 0) {
        return 1;
    }
    return 100;
}

int main(int argc, char* argv[]) {
    int exponentNum;
    float baseNum, returnNum;

    if (argc == 3) {
        baseNum = atoi(argv[1]);
        exponentNum = atoi(argv[2]);
    } else {
        printf("\nPlease enter base number:\n");
        scanf("%f", &baseNum);
        printf("\nPlease enter exponent:\n");
        scanf("%d", &exponentNum);
    }

    returnNum = toPower(baseNum, exponentNum);

    printf("\nResult: %f\n", returnNum);

    return 0;
}
