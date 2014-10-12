#include <stdio.h>

int main(int argc, char* argv[]) {
    char* p;
    char str[6] = "frank";
    p = str;
    printf("str: %s\np: %s\n", str, p);
    *p = "bar";
    printf("str: %s\np: %s\n", str, p);

    return 0;
}
