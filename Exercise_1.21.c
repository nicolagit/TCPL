#include <stdio.h>
#include <string.h>

#define MAXLINE 80
#define TAB_SIZE 8

void entab(char input[], char output[], int tabsize);

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

	entab(input, output, TAB_SIZE);
	printf("%s \n", output);
	return 0;
}

/* Go through the chars and if blank(s) are found then
 * replace it/them with tabs+blanks, giving priority to tabs.
 * If 1 tab or 1 blank will both fit the request, then use tab.
 */
void entab(char in[], char out[], int tabsize) {
	int i_in = 0;
	int i_out = 0;
	int cnt = 0;

	for (i_in=0; in[i_in]!='\0'; i_in++) {
		if (in[i_in]!=' ') {
 // 1. If a normal char is found, then in is copied to output.
			if (cnt==0) {
				out[i_out] = in[i_in];
				i_out++;
			}
			else if (cnt>0) {
 // 4. If a normal char is found when cnt > 0, fulfill out with blanks
				for (;cnt>0;cnt--) {
					out[i_out] = '_';
					i_out++;
				}
				out[i_out] = in[i_in];
				i_out++;
			}
		}
		else if (in[i_in]==' ') {
 //2. If blanks are found, increase cnt
			cnt++;
			if ((i_in+1)%tabsize == 0) {
 //3. If cnt reached the size of a column, then add '\t' a reset cnt
				out[i_out] = '\t';
				cnt = 0;
				i_out++;
			}
		}
	}
}
