/* Write a function _invert(x,p,n,)_ that returns _x_ with the _n_ bits
 * that begin at position _p_ inverted (i.e., 1 changed into 0 and vice versa), leaving
 * the others unchanged.
 */

#include <stdio.h>

int invert(int x, int p, int n)
{
	return x ^ ( (~0 << p) ^ (~0 << (p-n)) );
}

int main ()
{
	printf("%d\n", invert(352, 6, 4));
	printf("%d\n", invert(4095, 6, 4));
}
