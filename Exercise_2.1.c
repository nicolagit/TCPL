#include <stdio.h>
#include <limits.h>

int main() {
        printf("min char size: %d\n", CHAR_MIN);
        printf("max char size: %d\n", CHAR_MAX);
        printf("range char: %d\n", (CHAR_MAX-CHAR_MIN));
        printf("max+range unsigned char: 0-%d\n", UCHAR_MAX);
        printf("min short int size: %d\n", SHRT_MIN);
        printf("max short int size: %d\n", SHRT_MAX);
        printf("range short int: %d\n", (SHRT_MAX-SHRT_MIN));
        printf("max+range unsigned short int: 0-%d\n", USHRT_MAX);
        printf("min int size: %d\n", INT_MIN);
        printf("max int size: %d\n", INT_MAX);
        printf("range int: %ld\n", ((long)INT_MAX-INT_MIN));
        printf("max+range unsigned int size: 0-%ld\n", UINT_MAX);
        printf("min long int size: %ld\n", LONG_MIN);
        printf("max long int size: %ld\n", LONG_MAX);
}
