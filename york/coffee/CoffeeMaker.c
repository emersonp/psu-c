// Copyright (c) 2014 Parker Harris Emerson
// Coffee Maker, generates coffee data for coffee.c assignment in New Beginnings York Class.

#include <stdio.h>

int main() {
    printf("100 100 10000 4\n");
    for (int i = 1; i < 101; i++) {
        for (int k = 1; k < 101; k++) {
            printf("%d %d\n", i, k);
        }
    }
    printf("1\n3\n5\n11\n0 0 0 0");

    return 0;
}
