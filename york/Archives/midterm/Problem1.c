// Parker Harris Emerson, York Midterm Problem 1
//
// I had three test cases working,  but I've spent an hour on this program and I can see that my structure / pseudocode was flawed, and alas, I do not have time to move forward on this any further.

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Including these because time pressure, may not need all three.

int user_num;
int bit_counter = 0;
int bit_increment = 0;
int larger_num = 0;
int smaller_num = 0;
int zero_loc = 0;
int interim_num = 0;

int main(int argc, char* argv[]) {
    if (argc == 2) {
        sscanf(argv[1], "%d", &user_num);
    } else {
        printf("Please enter a positive integer.\n");
        scanf("%d", &user_num);
    }

    do {
        if (user_num & 1 << bit_increment) {
            bit_counter++;
        }
        bit_increment++;
    } while (1 << bit_increment <= user_num);

    // printf("Bit_Counter: %d\n", bit_counter);
    // printf("Bit_Increment: %d\n", bit_increment);
    // printf("User_Num: %d\n", user_num);

    if ((((1 << bit_increment) - 1) | user_num) == user_num) { // check if user_num is all 1s; a number that is all 1 bits cannot have a smaller (positive) number with the same number of 1 bits; will address negative answer given time
        larger_num = (1 << bit_increment & (unsigned) user_num >> 1);
        smaller_num = -1;
    } else {
        for (int i = 0; i < bit_increment; i++) {
            if (!(user_num & (1 << i))) {
                larger_num = (user_num | 1 << i);
                zero_loc = i;
                break;
            }
        }
        interim_num = larger_num;
        for (int j = zero_loc - 1; j > 0; j--) {
            if (larger_num & 1 << j) {
                larger_num = (larger_num ^ (1 << j));
                break;
            }
        }
    }

    if (smaller_num >= 0) {
        for (int i = zero_loc + 1; i < (1 << bit_increment); i++) {
            if (interim_num & 1 << i) {
                smaller_num = (interim_num ^ (1 << i));
                break;
            }
        }
    }

    printf("Larger Number: %d\n", larger_num);
    if (smaller_num > 0) {
        printf("Smaller Number: %d\n", smaller_num);
    }


    return 0;
}
