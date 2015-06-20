#include <stdio.h>

main()
{
	int blanks, tabs, newlines = 0;
	int c = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blanks;
		if (c == '\t')
			++tabs;
		if (c == '\n')
			++newlines;
	}
	printf("blanks = %d, tabs = %d, newlines = %d", blanks, tabs, newlines);
}
