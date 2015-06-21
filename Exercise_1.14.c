#include <stdio.h>

main()
{
	int asciiArray[255];
	int c, i, ii;
	
	for (i = 0; i < 255; ++i)
		asciiArray[i] = 0;


	while ((c = getchar()) != EOF) {
		++asciiArray[c];
	}

	for (i = 0; i < 255; ++i) {
		if (asciiArray[i] > 0) {
			printf("char %c (code %3d): ", i, i);
			for (ii = 0; (ii < asciiArray[i] && ii < 60); ++ii) {
				printf("-");
			}
			printf("\n");
		}
	}
}
