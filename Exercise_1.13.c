#include <stdio.h>

# define IN 1
# define OUT 0

main()
{
	int c, word, length, state;
	int lengthOfWord[50];
	int i, ii;
	state = OUT;
	c = word = length = 0;
	for (i = 0; i < 50; ++i)
		lengthOfWord[i] = 0;
	
	while ((c = getchar()) != EOF) {
		++length;
		if (c == ' ' || c == '\n' || c == '\t') {
		state = OUT;
		lengthOfWord[word] = length;
		length = 0;
		++word;
		}
		else if (state == OUT) {
			state = IN;
		}
	}
	for (i = 15; i > 0; --i) {	/* 15 is the limit for words' length */
		for (ii = 0; ii < word; ++ii) {
			if ( lengthOfWord[ii] > i )
				printf("|");
			else printf(" ");
		}
		printf("\n");
	}
}

