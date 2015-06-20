#include <stdio.h>

main()
{
	int nc = 0;

	while ((nc = getchar()) != EOF) {
		if (nc == '\t') {
			putchar('\\');
			putchar('t');
		}
		if (nc == '\b') {
			putchar('\\');
			putchar('b');
		}
		if (nc == '\\') {
			putchar('\\');
			putchar('\\');
		}
		if ( (nc != '\t') && (nc != '\b') && (nc != '\\') )
			putchar(nc);
	}
}
