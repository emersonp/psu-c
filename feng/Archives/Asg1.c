// Copyright (c) 2014 Parker Harris Emerson
// Assignment 1 for New Beginnings Fall 2014, Assigned by Wu-chang Feng.
// Write a program that randomizes the alphabet, then asks the user to type the new alphabet, halting if they get it wrong and timing their ability to do so.

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
    char startAlph[27] = "abcdefghijklmnopqrstuvwxyz";
    //strcpy(startAlph, "abcdefghijklmnopqrstuvwxyz");
    char tempChar1;
    char tempChar2;
    int tempLoc1;
    int tempLoc2;
    char typedChar[27];

    // Get time of day in ms and use to seed random
    struct timeval programTime;
    struct timeval loopTime;
    struct timeval doneTime;
    gettimeofday(&programTime, NULL);
    srand(programTime.tv_usec);

    // Swap two random characters in startAlph 13 times. Thirteen times is the number Simon gave for guaranteed randomization (all possible permutations possible).
        for (int i = 0; i < 13; i++) {
            tempChar1 = startAlph[tempLoc1 = (rand()%26)];
            tempChar2 = startAlph[tempLoc2 = (rand()%26)];
            startAlph[tempLoc1] = tempChar2;
            startAlph[tempLoc2] = tempChar1;
        }
    
    // Request typing from user.
    do {
        gettimeofday(&loopTime, NULL);
        printf("Type the following string (followed by <enter>):\n%s\n", startAlph);
        scanf("%s", &typedChar[0]); // If user types alphabet correctly and keeps going, program will register as correct input.
        if (strcmp(startAlph, typedChar) == 0) {
            printf("\nCorrect!\n");
            break;
        }
        printf("\nIncorrect. Try again.\n");
    } while (1);

    // Print time taken to type in input.
    gettimeofday(&doneTime, NULL);
    timersub(&doneTime, &loopTime, &loopTime);
    timersub(&doneTime, &programTime, &doneTime);
    int progDiffTime = doneTime.tv_sec;
    long progDiffTimeUsec = doneTime.tv_usec;
    int loopDiffTime = loopTime.tv_sec;
    long loopDiffTimeUsec = loopTime.tv_usec;
    printf("It took you %d seconds (%ld microseconds) to type the whole thing correctly!\n", progDiffTime, progDiffTimeUsec);
    printf("It took you %d seconds (%ld microseconds) to type it correctly the last time!\n", loopDiffTime, loopDiffTimeUsec);

}    

