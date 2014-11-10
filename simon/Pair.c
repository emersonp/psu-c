// Pair Programming with Kainoa
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* ascii_str = "abcdefghijklmnopqrstuvwxyz";

char* reverse(char* string) {
    int str_len = (int) strlen(string);
    char* new_str = NULL;
    new_str = (char*)(malloc(sizeof(char) * str_len));

    for (int i = str_len - 1; i >= 0; i--) {
        new_str[25 - i] = ascii_str[i];
    }

    return new_str;
}

void sort(char* input_str) {
    char* string = input_str;
    for (int i = 0; i < (int)strlen(string) - 1; i++) {
        for (int j = i + 1; j < (int)strlen(string); j++) {
            if (string[i] > string[j]) {
                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
}


int anagram(char* string1, char* string2) {
    if (strlen(string1) != strlen(string2)) {
        return 0;
    } // If not same length, not anagram string.
    sort(string1);
    sort(string2);
    return !strncmp(string1, string2, strlen(string1));
}

int** rotate(int** array) {
    int tempArray = (int)(malloc(sizeof(array)));
    memcpy(array, tempArray, sizeof(tempArray));
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            tempArray[x][y] = array[3 - y][x];
        }
    }
    return tempArray;
}


int main() {
    printf("%d\n", (int) strlen(ascii_str));

    printf("reverse: %s\n", reverse(ascii_str));

    char frank[50] = "frankandbeans";
    char beans[50] = "beansandfrank";
    if (anagram(frank, beans)) {
        printf("Anagram true!\n");
    }

    int testMatrix[3][3];
    int testNum = 1;
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            testMatrix[x][y] = testNum++;
        }
    }
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%d ", testMatrix[x][y]);
        }
        printf("\n");
    }
    int** tempArray = (int)(malloc(sizeof(array)));
    memcpy(array, tempArray, sizeof(tempArray));
    tempArray = rotate(testMatrix);

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            printf("%d ", testMatrix[x][y]);
        }
        printf("\n");
    }
}
