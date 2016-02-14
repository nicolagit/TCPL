/* Write the function _strrindex(s,t)_, which returns the position
 * of the _rightmost_ occurrence of _t_ in _s_, or -1 if there is none
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum inout line length */

int getline2(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find al lines matching pattern */
int main()
{
	char line[MAXLINE];
	int found = 0;

	while (getline2(line, MAXLINE) > 0)
		if (strrindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

/* getline2: get line into s, return length */
int getline2(char s[], int lim)
{
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/* strrindex: return index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
	int i,j,k,lastmatch=-1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			lastmatch=i;
	}
	printf("%d\n", lastmatch);
	return lastmatch;
}
