// Celeb.c
// Copyright (c) 2014 Parker Harris Emerson; based (extensively) on scaffolding provided by Bryant York
/*
Splits an array of "house values" so that each of two parties has equal amounts of property, returning amount of "house value" that must be sold to split assets cashwise equally.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void sort(int num, unsigned int data[]) {
    int tmpSwap;
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (data[i] != 0 && data[i] < data[j]) {
                tmpSwap = data[i];
                data[i] = data[j];
                data[j] = tmpSwap;
            }
        }
    }
}

int findPartition(int arrLen, unsigned int array[]) {
    unsigned int firstHalf = 0, secondHalf = 0;

    for (int i = 0; i < pow(2, arrLen); i++) {
        for (int k = 0; k < arrLen; k++) {
            if (array[k] && (1 << (arrLen - k - 1) & i)) {
                firstHalf += array[k];
            } else {
                secondHalf += array[k];
            }
        }
        if (firstHalf == secondHalf) {
            return 1;
        }
        firstHalf = 0;
        secondHalf = 0;
    }

    return 0;
}

void removePartSums(int arrLen, unsigned int array[]) {
    unsigned int *testArr = NULL;
    testArr = (unsigned int*)(malloc(sizeof(unsigned int) * arrLen));
    for (int i = pow(2, arrLen); i > -1; i--) {
        
        // Zero out test array for new test.
        for (int k = 0; k < arrLen; k++) {
            testArr[k] = 0;
        }

        // If there is something in the array, and the bit test i passes, add value to same place in testArr.
        for (int j = 0; j < arrLen; j++) {
            if (array[j] && (1 << (arrLen - j - 1) & i)) {
                testArr[j] = array[j];
            }
        }

        //
        if (findPartition(arrLen, testArr)) {
            for (int m = 0; m < arrLen; m++) {
                if (testArr[m]) {
                    array[m] = 0;
                }
            }
        }
    }
    free(testArr);
}

int main(){

	FILE *f1; //the file containing Celebrity Split data
	int n, done;
	unsigned int m[24], mustSell = 0;
    for (int i = 0; i < 24; i++) {
        m[i] = 0;
    }

	f1 = fopen("CelebritySplit.txt","r");
	// check for file open error
	if (f1 == NULL) {
		printf("\nUnable to open CelebritySplit3.txt\n");
		exit(1);
	}
	
    done = 0;
	
    while (!done) {
        fscanf(f1,"%d",&n);
        // Do error checking here
        if (n==0) {printf("\nDone\n"); exit(0);}
        if (n>24) {printf("\nError - N > 24\n"); exit(1);}
        for (int i = 0; i < n; i++){
            fscanf(f1,"%u",&m[i]);
        }
        // Print input
        printf("\nInput\n");
        printf("\nN = %d\n",n);
        for (int i = 0; i  < n; i++){
            printf("\n%u",m[i]);
        }

        // first sort the mansions into descending order of value
        sort(n, m);
        
        // Print out the sorted mansions
        printf("\n\nSorted Input\n");
        for (int i = 0; i  < n; i++){
            printf("\n%u",m[i]);
        }
        printf("\n\n");

        // Remove equal summed partitions if possible.
        removePartSums(n, m);

        printf("\n\nAfter Subtractions\n");
        for (int i = 0; i  < n; i++){
            printf("\n%u",m[i]);
        }


        // Now compute the sum of the non-equal amounts
        for (int i = 0; i < n; i++) {
            mustSell += m[i];
        }
        printf("\n\nThe celebs must sell $%d worth of houses.\n", mustSell);
        mustSell = 0;
        }

}


