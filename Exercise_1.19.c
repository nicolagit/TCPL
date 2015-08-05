#include <stdio.h>
#include <string.h>
#define MAXLINE 80

void reverse(char input[], char output[]);

main()
{
	char input[MAXLINE] = "";	/* current input */
	char output[MAXLINE] = "";	/* reversed output */
	int i = 0;
	int c;

	while ((c=getchar())!=EOF && c!='\n') {
		input[i]=c;
		++i;
	}

	reverse(input, output); 
		printf("%s \n", output);

	return 0;
}

/* reverse word */
void reverse(char in[], char out[])
{
	int i = 0;
	int ii = 0;

	for (i=MAXLINE-1; i>=0; --i) {
		if (in[i]!='\0'){
			out[ii] = in[i];
			++ii;
		}
	}

}
