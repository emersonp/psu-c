// Parker Harris Emerson, York Midterm Problem 2
//
// I didn't quite understand what Simon was saying, but apparently the code provided is structured backward (?) to create the output in the problem example. I will endeavor to move forward regardless.

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Including these because time pressure, may not need all three.

void printBinary(unsigned int k) {
    // Prints binary value of k from left (low order bit)
    // to right (high order bit)
    for (int i = 0; i < 32; i++) {
        if (k & 1) {
            printf("1");
        } else {
            printf("0");
        }
        k >>= 1;
    }
    printf("\n");
}

int updateBits(unsigned int n, unsigned int m, int i, int j) {
    unsigned int nx;

    for (int x = 31; x >= 0; x--) {
        if (x > j || x < i) {
            nx = (n & (1 << x));
        } else {
            nx = (m & (1 << (x - i)));
        }
    }

    return nx;
                    
}


int main() {
    unsigned int n, m, nx;
    int i, j;

    printf("n m i j (where n, m, i, and j in decimal with m much less than n)\n");
    scanf("%u %u %d %d", &n, &m, &i, &j);

    printf("\n n = ");
    printBinary(n);
    printf("\n m = ");
    printBinary(m);

    printf("\ni = %d\nj = %d\n", i, j);

    nx = updateBits(n, m, i, j);

    printf("\nn = ");
    printBinary(nx);

    return 0;
}
