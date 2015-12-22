/* Write a function _rightrot(x,n)_ that returns the value of the
 * integer _x_ rotated to the right by _n_ bit positions.
 */

#include <stdio.h>

unsigned rightrot( unsigned x, int n)
{
	int i;
	for (i=0; i<n; i++) {
		if (x & ~(~0 << 1))
			x = (x >> 1) | (~(~0U >> 1));
		else
			x = x >> 1;
	}
	return x;
}


int main()
{
	printf("%u\n", rightrot(1, 2));
	printf("%u\n", rightrot(2, 4));
	printf("%u\n", rightrot(7, 2));
	printf("%u\n", rightrot(15, 2));
}
