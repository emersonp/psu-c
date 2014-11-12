// Copyright (c) 2014 Parker Harris Emerson
// Lab 5-5 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.
// Computer the function gcd(m, n) = gcd(n, m mod n), for m, n integers ≥ 1, using an algorithm that utilizes the decrease by variable size method. 

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcdGen(int m, int n) {
    if (n == 0) {
        return m;
    } else {
        return gcdGen(n, m % n);
    }
}


int main(int argc, char* argv[]) {
    int aNum = 0, bNum = 0;

    do {
        if (argc == 3) {
            aNum = atoi(argv[1]);
            bNum = atoi(argv[2]);
        } else {
            printf("\nPlease enter first number:\n");
            scanf("%d", &aNum);
            printf("\nPlease enter second number:\n");
            scanf("%d", &bNum);
        }
        
        if (aNum == 0 || bNum == 0) {
            printf("Please enter non-zero numbers.\n");
        } else {
            break;
        }
    } while (1);

    printf("The greatest common divisor of %d and %d is %d.\n", aNum, bNum, gcdGen(aNum, bNum));

    return 0;
}
