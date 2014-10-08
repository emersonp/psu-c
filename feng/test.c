#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int character = 10;
    char output[9];
    itoa(character, output, 2);
    printf("%s\n", output);

    return 0;
}
