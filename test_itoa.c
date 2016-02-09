#include <stdio.h>
#include <limits.h>
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
	printf("This is INT_MIN and proves that itoa doesn't work well. Convert int %d to string: ", INT_MIN); itoa(INT_MIN, s);
}

/* itoa: convert _n_ to characters in _s_ */
void itoa(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)	/* record sign */
		n = -n;		/* make positive */
	i = 0;
	do {	/* generate digits in reverse order */
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
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
