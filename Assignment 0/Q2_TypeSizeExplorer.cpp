#include <stdio.h>

int main() {
    printf("Size of short int: %zu bytes\n", sizeof(short int));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of long int: %zu bytes\n", sizeof(long int));
    printf("Size of long long int: %zu bytes\n", sizeof(long long int));
    printf("Size of unsigned int: %zu bytes\n", sizeof(unsigned int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n", sizeof(long double));
    printf("Size of char: %zu bytes\n", sizeof(char));

    return 0;
}
