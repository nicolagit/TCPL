#include <stdio.h>
#include <string.h>

#define MAXSTRING 999
#define MAXLINE 10

void removecomments(char input[], char output[], int maxline);

main() {
	char input[MAXSTRING] = "";
	char output[MAXLINE] = "";
	int c = 0;
	int i = 0;
	
	while ((c=getchar())!=EOF && c!='\0') {
		input[i]=c;
		++i;
	}
		input[i]='\0';

	removecomments(input, output, MAXLINE);
	printf("%s \n", output);
	return 0;
}

/* Remove C-style comments
 * from an input text
 */
void removecomments(char in[], char out[], int maxline) {
	int i = 0;
	int ii = 0;
	int bypass = 0;

	for (i=0; in[i]!='\0'; i++) {
		if (in[i]=='/' && in[i+1]=='*') {
			bypass=1;
		}
		if (bypass==1 && in[i-2]=='*' && in[i-1]=='/') {
			bypass=0;
		}
		if (bypass==0) {
			out[ii] = in[i];
			ii++;
		}
	}
	out[ii]='\0';
}
