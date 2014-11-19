/* Copyright (c) 2014 Parker  Harris Emerson
 * This program checks if three angles inputed from a text file following convetion given in class are a right triangle. Based on in class prompt given by Bryant York. 
 */

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


int main() {
    int side1, side2, side3;
    struct timeval timeA;
    struct timeval timeB, timeC, timeD;

    FILE * f1;

    //f1=fopen("Rich52.dfa","r");
    f1 = fopen("triangleData.txt", "r");
    printf("\n\n");

    while (1) {
        fscanf(f1, "%d", &side1);
        fscanf(f1, "%d", &side2);
        fscanf(f1, "%d", &side3);
        if (side1 == 0 || side2 == 0 || side3 == 0) {
            break;
        }
        gettimeofday(&timeA, NULL);
        side1 = side1 * side1;
        side2 = side2 * side2;
        side3 = side3 * side3;
        if (side1 + side2 == side3 || side2 + side3 == side1 || side1 + side3 == side2) {
            gettimeofday(&timeB, NULL);
            printf("right\n");
        } else {
            gettimeofday(&timeB, NULL);
            printf("wrong\n");
        }
        timersub(&timeB, &timeA, &timeC);
        timeradd(&timeC, &timeD, &timeD);
        
    }
    fclose(f1);
    int tvSec = timeD.tv_sec;
    long tvUSec = timeD.tv_usec;

    printf("sec: %d\tusec: %ld\n\n", tvSec, tvUSec);

    return 0;
}
