/* ...write a faster version of _bitcount_ */

#include <stdio.h>

int bitcount2(int x)
{
	int b=0;
	while (x != 0) {
		b++;
		x &= (x-1);
	}
	return b;
}

int main()
{
	int i;
	for (i=-128; i<127; i++)
		printf("bits in %d --> %d\n", i, bitcount2(i));
}
