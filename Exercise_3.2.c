/* Write a function _escape(s,t) that converts character like newline and tab
 * into visible escape sequences like _\n_ and _\t_ as it copies the string _t_
 * to _s_. Use a _switch_. Write a function for the other direction as well,
 * converting escape sequences into real characters.
 */

#include <stdio.h>

#define MAXLENGTH 1000


/* converts special characters into visible characters */
char escape (char s[], char t[]);

/* converts escape sequences into real characters */
char escape2 (char t[], char s[]);


int main()
{
	char s[MAXLENGTH], t[MAXLENGTH];

	char t1[] = "sou\nr\tce";
	escape(s,t1);
	printf("\nescape:\n  -- in: --\n%s\n\n  -- out: --\n%s\n\n", t1, s);
	escape2(t,s);
	printf("\nescape2:\n  -- in: --\n%s\n\n  -- out: --\n%s\n\n", s, t);

	char t2[] = "an\tother sou\nr\\ce";
	escape(s,t2);
	printf("\nescape:\n  -- in: --\n%s\n\n  -- out: --\n%s\n\n", t2, s);
	escape2(t,s);
	printf("\nescape2:\n  -- in: --\n%s\n\n  -- out: --\n%s\n\n", s, t);
}

/* converts special characters into visible characters */
char escape (char s[], char t[])
{
	int i, ii;

	/* clear the destination array */
	for (ii=0; ii<MAXLENGTH; ii++) {
		s[ii] = '\0';
	}

	i = ii = 0;
	while ( (t[i] != '\0') && (ii<MAXLENGTH) ) {
		switch (t[i]) {
		case '\\':
			s[ii++] = '\\';
			s[ii] = '\\';
			break;
		case '\n':
			s[ii++] = '\\';
			s[ii] = 'n';
			break;
		case '\t':
			s[ii++] = '\\';
			s[ii] = 't';
			break;
		case ' ': /* this is not an escaping character, i'll keep it anyway */
			s[ii] = '_';
			break;
		default:
			s[ii] = t[i];
			break;
		}
		i++;
		ii++;
	}
}


/* converts escape sequences into real characters */
char escape2 (char t[], char s[])
{
	int i, ii;

	/* clear the destination array */
	for (ii=0; ii<MAXLENGTH; ii++) {
		t[ii] = '\0';
	}

	i = ii = 0;
	while ( (s[i] != '\0') && (ii<MAXLENGTH) ) {
		switch (s[i]) {
		case '\\':
			switch (s[++i]) {
				case '\\':
					t[ii] = '\\';
					break;
				case 'n':
					t[ii] = '\n';
					break;
				case 't':
					t[ii] = '\t';
					break;
				case '_': /* this is not an escaping character, i'll keep it anyway */
					t[ii] = ' ';
					break;
			}
			break;
		default:
			t[ii] = s[i];
		}
		i++;
		ii++;
	}
}
