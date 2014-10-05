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
    char* startAlph = "abcdefghijklmnopqrstuvwxyz";
    int alphLength = 26;
    int tempLengthIndex;
    char tempChar;
    char* newAlph = NULL;
    newAlph = (char*) (malloc(sizeof(char) * alphLength));
    char* tempAlph = NULL;
    char typedChar[26];

    // Get time of day in ms and use to seed random
    struct timeval programTime;
    struct timeval loopTime;
    struct timeval doneTime;
    gettimeofday(&programTime, NULL);
    srand(programTime.tv_usec);

    // Pull a random letter from startAlph and create newAlph, putting letter into newAlph
    do {    
        tempChar = startAlph[(rand()%alphLength)];
        // printf("Temp char: %c\n", tempChar);
        newAlph[26-alphLength] = tempChar;
        tempAlph = (char*) (malloc(sizeof(char) * alphLength - 1));
        tempLengthIndex = 0;
        for (int i = 0; i < alphLength; i++) {
            if (startAlph[i] != tempChar) {
                tempAlph[tempLengthIndex] = startAlph[i];
                tempLengthIndex++;
            }
        }
        alphLength--;
        startAlph = tempAlph;
        // For Simon - 'free(tempAlph);' seems to cause problems here - I am unsure as to why.
    } while (alphLength > 0);
    
    // Request character from user, ending if not letter of alphabet in order.
    do {
        gettimeofday(&loopTime, NULL);
        printf("Type the following string:\n%s\n", newAlph);
        scanf("%s", &typedChar[0]);
        if (strcmp(newAlph, typedChar) == 0) {
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

