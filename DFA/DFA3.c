/* Copyright (c) 2014 Parker  Harris Emerson
 This program (Parker3) implements a DFA over the alphabet Delta = {a,b}
 The DFA accepts the language consisting of words of the form
 where every 'a' is immediately followed by a 'b'.  The charcater
 'c' is used to terminate the word (input)
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NO_OF_STATES 10
#define MAX_ALPHABET_SIZE 10
#define MAX_NO_OF_ACCEPT_STATES 10

int main() {

    FILE * f1;

    int *delta;
    int alphabet_size;
    int accept_set_size;
    char alphabet[MAX_ALPHABET_SIZE];
    int acceptState[MAX_NO_OF_ACCEPT_STATES];
    int states[MAX_NO_OF_STATES];
    int s1, s2, n, cc;

    char temp, c;
    int currentState, startState, numStates;
    int nextState;
    int tempChar;
    char stopChar;

    //f1=fopen("Rich52.dfa","r");
    f1 = fopen("DFA.txt", "r");

    //Enter the number of states
    fscanf(f1, "%d", &numStates);
    printf("Num States: %d\n", numStates);

    //  do error checking here

    // Enter the state names, these will eventually be strings.
    for (int i = 0; i < numStates; i++) {
        fscanf(f1, "%d", &states[i]);
        printf("States: %d\n", states[i]);
    }

    // Enter the alphabet size
    fscanf(f1,"%d", &alphabet_size);
    printf("Alph. Size: %d\n", alphabet_size);

    // do error checking hhere

    // Enter the characters of the alphabet
    for (int i = 0; i<alphabet_size; i++) {
        fscanf(f1, " %c", &alphabet[i]);
        printf("Char in Alph: %c\n", alphabet[i]);
    }

    // Enter the stopChar
    fscanf(f1, " %c", &stopChar);
    printf("Stop Char: %c\n", stopChar);

    // Enter the start state
    fscanf(f1,"%d", &startState);
    printf("Start State: %d\n", startState);

    // Enter the size of the set of accept states
    fscanf(f1,"%d", &accept_set_size);

    //Enter the accept state names
    for (int i = 0; i<accept_set_size; i++) {
        fscanf(f1, "%d", &acceptState[i]);
    }

    n = numStates * alphabet_size;

    // malloc space delta (the transition function)
    delta = (int *)(malloc(n * sizeof(int)));

    for (int i = 0; i < n; i++) {
        fscanf(f1, "%d %c %d", &s1, &c, &s2);
        cc = ((int) c ) - 97;
        delta[s1 * 2 + cc] = s2;
        // *(delta + s1 * 8 + cc * 4) = s2;
    }

    fclose(f1);

    for (int i = 0; i < n; i++) {
        printf("\n delta[%d] = %d\n", i, delta[i]);
    }

    currentState = startState;

    printf("\nPlease enter a number of a's and b's, followed by a %c.\n", stopChar);
    while (1) {
        scanf("%c", &temp);
        tempChar = temp - 'a';
        
        if (tempChar == stopChar - 'a') {
            break;
        } else if (tempChar == 0 || tempChar == 1) {
            nextState = delta[currentState * 2 + tempChar];
            currentState = nextState;
        } else if (tempChar == -98 || tempChar == -87) {
            break;
        } else {
            printf("Illegal character.\n");
            exit(0);

        }
    }
    
    if (currentState == acceptState[0]) {
        printf("\nAccept.\n");
    } else {
        printf("\nReject.\n");
    }
    return 0;
}
