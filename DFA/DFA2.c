/* Copyright (c) 2014 Parker  Harris Emerson
 * 
 * Allows user input to create a DFA, which accepts any number
 * of 'a's, each immediately followed by a 'b'
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {

    char temp;
    int currentState = 0, startState = 0, numStates = 0;
    int nextState = 0;
    int tempChar;
    char stopChar = 'c';

    // file vars
    int sizeQ = 0;
    int sizeAlpha = 0;
    int sizeAccept = 0;
    int numFunctions = 0;
    int* allStates = NULL;
    char* allAlpha = NULL;
    int* allAccept = NULL;
    int* allFunctions[3];

    FILE* fileHandle = fopen("DFA.txt", 'r');
    {
        fscanf(fileHandle, "%d", &sizeQ);
        allStates = (int*)(malloc(sizeof(int) * sizeQ));
        for (int i = 0; i < sizeQ; i++) {
            fscanf(fileHandle, "%d", &allStates[i]);
        }
        fscanf(fileHandle, "%d", &sizeAlpha);
        allAlpha = (char*)(malloc(sizeof(char) * sizeAlpha));
        for (int i = 0; i < sizeAlpha; i++) {
            fscanf(fileHandle, "%c", &allAlpha[i]);
        }
        fscanf(fileHandle, "%c", &stopChar);
        fscanf(fileHandle, "%d", &startState);
        fscanf(fileHandle, "%d", &sizeAccept);
        for (int i = 0; i < sizeAccept; i++) {
            fscanf(fileHandle, "%d", &allAccept[i]);
        }
        numFunctions = pow(sizeQ, (sizeQ * sizeAlpha));
        allFunctions[0] = (int*)(malloc(sizeof(int) * numFunctions));
        allFunctions[1] = (char*)(malloc(sizeof(char) * numFunctions));
        allFunctions[2] = (int*)(malloc(sizeof(int) * numFunctions));

        for (int y = 0; y  < numFunctions; y++) {
            for (int x = 0; x < 3; x++) {
                fscanf(fileHandle, "%d", &allFunctions[x][y]);
            }
        }
    }
    fclose(fileHandle);

    currentState = startState;

    printf("\nPlease enter a number of a's and b's, followed by a %c.\n", stopChar);
    while (1) {
        scanf("%c", &temp);
        tempChar = temp - 'a';
        
        if (tempChar == 2) {
            break;
        } else if (tempChar == -98 || tempChar == -87) {
            break;
        } else {
            for (int i = 0; i < numFunctions; i++) {
                if (allFunctions[0][i] == currentState) {
                    if (allFunctions[1][i] == temp) {
                        nextState = allFunctions[2][i];
                    }
                }
            }
            currentState = nextState;
        }
    }
   
    if (currentState == acceptState) {
        printf("\nAccept.\n");
    } else {
        printf("\nReject.\n");
    }
    
    return 0;
}
