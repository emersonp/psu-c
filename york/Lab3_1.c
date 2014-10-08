// Copyright (c) 2014 Parker Harris Emerson
// Lab 3-1 Assignment for New Beginnings Fall 2014, Assigned by Bryant York.

// Given an array of n characters called the text and an array of m characters called the pattern, find a substring of the text that matches the pattern. To be more precise, we want to find i, the index of the leftmost character of the first matching substring in the text. Use brute force string matching. The input file is named “data5.txt”. Its first element is a positive integer denoting the length (number of characters) in the text string, followed by a newline, followed by the actual text string, followed by a newline, followed by an integer denoting the length of the pattern string, followed by a newline, followed by the actual pattern string. Your C program should print out the pattern string, then the text string, and then print a “^” beneath the first character where the pattern appears in the text.

// Simon says: A complete list of includes.
#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    // Initialize and declare search variables.
    int textSize = 0;
    int patternSize = 0;
    char* textArr = NULL;
    char* patternArr = NULL;
    int foundIndex = -1;

    // Open file, assign to fileHandle
	FILE* fileHandle = fopen("./Data5.txt", "r");
	{
		// Grab first integer value, which declares number of chars in string.
        fscanf(fileHandle, "%d", &textSize);

		// Establish array textArr, setting appropriate size, then fill.
        textArr = (char*) (malloc(sizeof(char) * textSize));
        fscanf(fileHandle, "%s", textArr);

        // Grab second integer value, which declares number of chars in pattern string.
        fscanf(fileHandle, "%d", &patternSize);

		// Establish array textArr, setting appropriate size.
        patternArr = (char*) (malloc(sizeof(char) * patternSize));
        fscanf(fileHandle, "%s", patternArr);

	}
    
    // Super important - close the file.
	fclose(fileHandle);
    
    // Run through the text array, doing a brute force mini loop looking for the pattern, either continuing the mini loop, setting the foundIndex to the found index if reaching end of miniloop, or breaking from miniloop if not there.
    for (int i = 0; i < (textSize - patternSize); i++) {
        for (int j = 0; j < patternSize; j++) {
            if (j == patternSize - 1) {
                foundIndex = i;
            }
            else if (patternArr[j] != textArr[i + j]) {
                break;
            }
        }
    }
    // Print ALL the things!
    printf("Pattern String: %s\n\n", patternArr);
    printf("Text Pattern: \n");
    
    for (int k = 0; k < textSize; k += 50) {
        for (int m = 0; m < 50; m++) {
            printf("%c", textArr[k + m]);
        }
        printf("\n");
        for (int n = 0; n < 50; n++) {
            if (k + n == foundIndex) {
                printf("^");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
