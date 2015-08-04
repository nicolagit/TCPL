#include <stdio.h>
#include <string.h>
#define MAXLINE 80	/* maximum input line size */

int getline2(char output[], int maxline);

/* remove blanks, tabs and entirely empty lines */
main()
{
	int len;			/* current line length */
	char line[MAXLINE] = "";	/* current input line */
	char output[MAXLINE] = "";	/* filtered line */

	while ((len = getline2(output, MAXLINE)) > 0 ) 
		printf("%s \n", output);

	return 0;
}

/* getline: read a line into s, return length */
int getline2(char out[], int lim)
{
	int c;
	int i = 0;
	int ii = 0;


	memset(&out[0], 0, MAXLINE * (sizeof out[0]));

	while (i<lim && (c=getchar())!=EOF && c!='\n') {
		if (c != ' ' && c!='\t') {
			out[ii] = c;
			++ii;
		}
		++i;
		if (i == MAXLINE)
			printf("Input was trunked to %i chars \n", MAXLINE);

	}
	return i;
}
