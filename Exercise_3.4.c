/* In a two's complement number representation, our version of
 * _itoa_ does not handle the largest negative number, that is, the value _n_ equal
 * to -(2^(wordsize-1)). Explain why not. Modify it to print that value correctly,
 * regardless of the machine on which it runs.
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAXLINE 20

/* itoa: convert _n_ to characters in _s_ */
void itoa(int n, char s[]);

/* just print */
void reverse(char in[]);

int main()
{
	char s[MAXLINE];
	printf("Convert int %d to string: ", 534); itoa(534, s);
	printf("Convert int %d to string: ", 0); itoa(0, s);
	printf("Convert int %d to string: ", -2314); itoa(-2314, s);
	printf("Convert int %d to string: ", 3408327); itoa(3408327, s);
	printf("Convert int %d to string: ", -3498345); itoa(-3498345, s);
	printf("This is INT_MAX. Convert int %d to string: ", INT_MAX); itoa(INT_MAX, s);
	printf("This is INT_MIN. Convert int %d to string: ", INT_MIN); itoa(INT_MIN, s);
	printf("\n----------\nNOTE:\nWith the Two's complement, negative values of a signed type are larger than\npositive value by 1 unit.\nE.g. in a signed 3-bit type, the max positive is 3 and max negative is -4.\nTherefore we can't just invert the max negative number (it remains negative)\n");
}

/* itoa: convert _n_ to characters in _s_ */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make positive */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = abs(n % 10) + '0';	/* get next digit */
	} while ((n /= 10) != 0);	/* delete it */
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
