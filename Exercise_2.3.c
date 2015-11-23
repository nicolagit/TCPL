#include <stdio.h>

int main()
{
/*
 * Converts a string of hex into int.
 * The hex can start with 0x, 0X or nothing (just the value)
 * and it can use a-f or A-F.
 */
        int htoi (char s[])
        {
                int n=0, i=0;
                if (s[i]=='0' && (s[i+1]=='x' || s[i+1]=='X'))
                        i=i+2;

                for (; s[i]!=NULL; i++) {
                        if (s[i] >= '0' && s[i] <= '9')
                                n= n * 16 + s[i] - '0';
                        else if (s[i] >= 'a' && s[i] <= 'f')
                                n= n * 16 + s[i] - 'a' + 10;
                        else if (s[i] >= 'A' && s[i] <= 'F')
                                n= n * 16 + s[i]- 'A' + 10;
                }
                return n;
        }

        printf("%d\n", htoi("3d0A")); //15626
        printf("%d\n", htoi("0xB3c")); //2876
        printf("%d\n", htoi("0X3fF")); //1023

}
