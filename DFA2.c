/* Copyright (c) 2014 Parker  Harris Emerson
 *
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main() {

    char temp;
    int currentState = 0, startState = 0, acceptState = 0, numStates = 0;
    int nextState = 0;
    int tempChar;
    char stopChar = 'c';

    int sigma[2][3];
    sigma[0][0] = 1;
    sigma[1][0] = 0;
    sigma[0][1] = 2;
    sigma[1][1] = 0;
    sigma[0][2] = 2;
    sigma[1][2] = 2;


    printf("\nEnter the number of states.\n");
    scanf("%d", &numStates);

    printf("\nEnter the start state.\n");
    scanf("%d", &startState);

    printf("\nEnter the accept state.\n");
    scanf("%d", &acceptState);

    scanf("%c", &temp); // Flush last character in stdin.

    currentState = startState;

    printf("\nPlease enter a number of a's and b's, followed by a %c.\n", stopChar);
    while (1) {
        scanf("%c", &temp);
        tempChar = temp - 'a';
        
        if (tempChar == 2) {
            break;
        } else if (tempChar == 0 || tempChar == 1) {
            nextState = sigma[currentState][tempChar];
            currentState = nextState;
        } else if (tempChar == -98 || tempChar == -87) {
            break;
        } else {
            printf("Illegal character.\n");
            exit(0);
        }
    }
    
    if (currentState == acceptState) {
        printf("\nAccept.\n");
    } else {
        printf("\nReject.\n");
    }
    
    return 0;
}
