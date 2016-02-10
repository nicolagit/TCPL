/* Write the function _itob(n,s,b)_ that converts the integer _n_
 * into a base _b_ character representation in the string _s_. In particular,
 * _itob(n,s,16)_ formats _n_ as a hexadecimal integer in _s_.
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAXLINE 20

/* itob: convert _n_ to characters in _s_ with base _b_ representation */
void itob(int n, char s[], int b);

/* just print */
void reverse(char in[]);

int main()
{
	char s[MAXLINE];
	printf("Convert int %d to base %d: ", 534, 4); itob(534, s, 4);
	printf("Convert int %d to base %d: ", 0, 8); itob(0, s, 8);
	printf("Convert int %d to base %d: ", -2314, 16); itob(-2314, s, 16);
	printf("Convert int %d to base %d: ", 3408327, 10); itob(3408327, s, 10);
	printf("Convert int %d to base %d: ", -3498345, 8); itob(-3498345, s, 8);
	printf("This is INT_MAX. Convert int %d to base %d: ", INT_MAX, 16); itob(INT_MAX, s, 16);
	printf("This is INT_MIN. Convert int %d to base %d: ", INT_MIN, 16); itob(INT_MIN, s, 16);
}

/* itob: convert _n_ to characters in _s_ with base _b_ representation */
void itob(int n, char s[], int b)
{
	int i, sign;
	char value[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make positive */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = value[abs(n % b)];	/* get next digit */
	} while ((n /= b) != 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

/* just print */
void reverse(char s[])
{
	int i = 0;

	while (s[++i] != '\0');		/* Find the length of the string */
	
	do {
		printf("%c", s[--i]);	/* Start from the length and print the string backward */
	} while (i > 0);
	printf("\n");
}
