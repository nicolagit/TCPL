/* Write a function _setbits(x,p,n,y)_ that returns _x_ with the _n_
 * bits that begin at position _p_ set to the rightmost _n_ bits of _y_, leaving the other
 * bith unchanged.
 */

#include <stdio.h>

int itobit (int x)
{
	int i, y = 0;
	for (i=0; i<x; i++) {
		y = (y << 1) | 1;
	}
	return y;
}

int setbits(int x, int p, int n, int y)
{
	return ( ( y & itobit(n) ) << ( p - n ) | ( x & ~( itobit(n) << ( p - n ) ) ) );
}

int main()
{
	printf("%d\n", setbits (0, 6, 3, 15));
	// 0 =        b.0000.0000.0000.0000
	// 15 =	      b.0000.0000.0000.1111
	//            b.0000.0000.0011.1000 (result)

	printf("%d\n", setbits (0, 6, 2, 15));
	// 0 =        b.0000.0000.0000.0000
	// 15 =	      b.0000.0000.0000.1111
	//            b.0000.0000.0011.0000 (result)

	printf("%d\n", setbits (240, 8, 4, 10));
	// 240 =      b.0000.0000.1111.0000
	// 10 =	      b.0000.0000.0000.1010
	//            b.0000.0000.1010.0000 (result)
	
	printf("%d\n", setbits (6519, 6, 3, 13));
	// 6519 =     b.0001.1001.0111.0111
	// 13 =	      b.0000.0000.0000.1101
	//            b.0001.1001.0110.1111 (result)
}

