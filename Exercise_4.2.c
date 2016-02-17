/* Extend _atof_ to handle scientific notation of the form
 * 123.45e-6
 * where a floating-point number may be followed by _e_ or _E_ and an optionally
 * signed exponent.
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]);

int main() {
	printf("\nConvert 123.45e-6: %.20f", atof("123.45e-6"));
	printf("\nConvert 123.456e+12: %f", atof("123.456e+12"));
	printf("\nConvert 123.456: %f", atof("123.456"));
	printf("\nConvert 10: %f", atof("10"));
	printf("\nConvert -10: %f", atof("-10"));
	printf("\nConvert 1 %f", atof("1"));
	printf("\nConvert -1 %f", atof("-1"));
	printf("\nConvert 1e-10 %f", atof("1e-10"));
	printf("\nConvert 3e-10 %f", atof("3e-10"));
	printf("\nConvert 3e3 %f", atof("3e3"));
	printf("\nConvert 3e+3 %f", atof("3e+3"));
}

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power, mant=1.0;
	int i, sign, mantsign=1;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if ((s[i++] == 'e') || (s[i++] == 'E')) {
		mantsign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (mant=0.0; isdigit(s[i]); i++) {
			mant = 10.0 * mant + (s[i] - '0');
		}
	}

	return pow(sign * val / power, mantsign * mant);
}
