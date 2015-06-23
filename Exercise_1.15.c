#include <stdio.h>

int fahr_to_celsius(int f);

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

main()
{
	int i;

	for (i = 0; i <= 300; i = i + 20) 
		fahr_to_celsius(i);
	
}

int fahr_to_celsius(int fahr) {
	int celsius;

	celsius = 5 * (fahr-32) / 9;
	printf("%d\t%d\n", fahr, celsius);
}
