/* Write a version of _itoa_ that accepts three arguments instead of
 * two. The third argument is a minimum field width; the converted number must
 * be padded with blanks on the left if necessary to make it wide enough
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAXLINE 20

/* itoa: convert _n_ to characters in _s_ */
void itoa(int n, char s[], int minwidth);

/* just print */
void reverse(char in[]);

int main()
{
	char s[MAXLINE];
	printf("Convert int %d to string, with min field width of %d: ", 534, 7); itoa(534, s, 7);
	printf("Convert int %d to string, with min field width of %d: ", 0, 3); itoa(0, s, 3);
	printf("Convert int %d to string, with min field width of %d: ", -2314, 6); itoa(-2314, s, 6);
	printf("Convert int %d to string, with min field width of %d: ", 3408327, 7); itoa(3408327, s, 7);
	printf("Convert int %d to string, with min field width of %d: ", -3498345, 10); itoa(-3498345, s, 10);
	printf("This is INT_MAX. Convert int %d to string, with min field width of %d: ", INT_MAX, 0); itoa(INT_MAX, s, 0);
	printf("This is INT_MIN. Convert int %d to string, with min field width of %d: ", INT_MIN, 20); itoa(INT_MIN, s, 20);
}

/* itoa: convert _n_ to characters in _s_ */
void itoa(int n, char s[], int minwidth)
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
	while (i < minwidth)	/* add padding blanks for minimum field width */
		s[i++] = '_';	/* _ instead of blank for easy read */
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
