// Copyright (c) 2014 Parker Harris Emerson
// Coffee Maker, generates coffee data for coffee.c assignment in New Beginnings York Class.

#include <stdio.h>

int main() {
    printf("1000 1000 250000 4\n");
    for (int i = 1; i < 1001; i++) {
        for (int k = 1; k < 1001; k++) {
            if (i < 501 && k > 500) {
                printf("%d %d\n", i, k);
            }
        }
    }
    printf("1\n3\n5\n11\n0 0 0 0");

    return 0;
}
