#include <stdio.h>
#include <string.h>

#define MAXLINE 80
#define TAB_SIZE 8

void detab(char input[], char output[], int tabsize);

main() {
	char input[MAXLINE] = "";
	char output[MAXLINE] = "";
	int c = 0;
	int i = 0;
	
	while ((c=getchar())!=EOF && c!='\n') {
		input[i]=c;
		++i;
	}
		input[i]='\0';

	detab(input, output, TAB_SIZE);
	printf("%s \n", output);
	return 0;
}

/* Go through the chars and if a \t is found
 * replaces it with blanks until next column,
 * i.e. until when "position of char mod tabsize = 0"
 */
void detab(char in[], char out[], int tabsize) {
	int i_in = 0;
	int i_out = 0;
	int i = 0;

	for (i_in=0; in[i_in]!='\0'; i_in++) {
		if (in[i_in]!='\t') {
			out[i_out] = in[i_in];
			i_out++;
		}
		else {
			for (i=tabsize-(i_out%tabsize); i>0; i--) {
				out[i_out] = ' ';
				i_out++;
			}
		}
	}
}
