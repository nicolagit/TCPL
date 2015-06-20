#include <stdio.h>

main()
{
	int nc = 0;
	int blank = 0;

	while ((nc = getchar()) != EOF) {
		if ( (blank == 0) || (nc != ' ') )
			putchar(nc);
		if (nc == ' ')
			blank = 1;
		else
			blank = 0;
	}
}
