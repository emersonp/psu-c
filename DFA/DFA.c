/* Copyright (c) 2014 Parker  Harris Emerson
 *
 * This program simulates a DFA that counts modulo number of states
 * beginning with an arbitary start state and accept state.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {

    char temp;
    int currentState = 0, startState = 0, acceptState = 0, numStates = 0;

    printf("\nEnter the number of states.\n");
    scanf("%d", &numStates);

    printf("\nEnter the start state.\n");
    scanf("%d", &startState);

    printf("\nEnter the accept state.\n");
    scanf("%d", &acceptState);

    scanf("%c", &temp); // Flush last character in stdin.

    currentState = startState;

    printf("\nPlease enter a number of 1s, followed by a 0.\n");
    while (1) {
        scanf("%c", &temp);
        if (temp == '0') {
            break;
        } else if (temp == '1') {
            currentState++;
            currentState = currentState % numStates;
        } else {
            printf("Illegal character.\n");
        }
    }
    
    if (currentState == acceptState) {
        printf("\nAccept.\n");
    } else {
        printf("\nReject.\n");
    }
    
    return 0;
}
