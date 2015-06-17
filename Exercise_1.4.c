#include <stdio.h>

/* print Celsius-Fahrenheit table
 * for celsius = -20, -10, ..., 150; floating-point version */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;	/* lower limit of temperature table */
	upper = 150;	/* upper limit */
	step = 10;	/* step size */

	printf("celsius fahr\n");
	celsius = lower;
	while (celsius <= upper) {
		fahr = (celsius / (5.0/9.0))+32.0;
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
