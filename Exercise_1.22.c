#include <stdio.h>
#include <string.h>

#define MAXSTRING 999
#define MAXLINE 10

void folding(char input[], char output[], int maxline);

main() {
	char input[MAXSTRING] = "";
	char output[MAXLINE] = "";
	int c = 0;
	int i = 0;
	
	while ((c=getchar())!=EOF && c!='\n') {
		input[i]=c;
		++i;
	}
		input[i]='\0';

	folding(input, output, MAXLINE);
	printf("%s \n", output);
	return 0;
}

/* Split a line longer than maxline into sub-lines.
 * The split happens at the first blank BEFORE the value of maxline.
 * If there are no blanks before the maxline, then the line is splitted at
 * maxline and a '_' is added
 */
void folding(char in[], char out[], int maxline) {
	int i_in = 0;
	int i_out = 0;
	int line_length = 0;
	int blank_pos = 0;

	for (i_in=0, i_out=0, line_length=0, blank_pos=0; in[i_in]!='\0' && in[i_in]!='\n'; i_in++, i_out++, line_length++) {
		out[i_out] = in[i_in];
		if (out[i_out] == ' ') {
			blank_pos = i_out;
		}
		if ((line_length+1)%maxline==0) {
			if (blank_pos!=0) {
				out[blank_pos] = '\n';
				line_length=i_out-blank_pos;
				blank_pos=0;
			}
			else {
				i_out++;
				out[i_out] = '_';
				i_out++;
				out[i_out] = '\n';
				line_length=0;
			}

		}
	}
	out[i_out]='\0';
}
