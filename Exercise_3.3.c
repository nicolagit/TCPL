/* Write a function _expand(s1,s2)_ that expands shorthand nota-
 * tions like a-z in the string s1 into equivalent complete list abc...xyz in
 * s2. Allow for letters of either case and digits, and be prepared to handle cases
 * like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.
 */

#include <stdio.h>

int expand (char s1[], char s2[]);

int main()
{
	char s1_01[] = "3-5";
	char s1_02[] = "a-5";
	char s1_03[] = "b-m";
	char s1_04[] = "L-B";
	char s1_05[] = "9-2";
	char s1_06[] = "C-D";
	char s1_07[] = "3-D";
	char s1_08[] = "a-z";
	char s1_09[] = "a-b-c";
	char s1_10[] = "a-z0-9";
	char s1_11[] = "-a-z";
	char s1_12[] = "a-z-";
	char s1_13[] = "-a-z-";
	char s1_14[] = "a-e-l";
	char s2[30];

	expand(s1_01, s2);
	expand(s1_02, s2);
	expand(s1_03, s2);
	expand(s1_04, s2);
	expand(s1_05, s2);
	expand(s1_06, s2);
	expand(s1_07, s2);
	expand(s1_08, s2);
	expand(s1_09, s2);
	expand(s1_10, s2);
	expand(s1_11, s2);
	expand(s1_12, s2);
	expand(s1_13, s2);
	expand(s1_14, s2);
}

int expand (char s1[], char s2[])
{
	int i = 0;
	int ii = 0;
	int from, to;

	// if the first char is a "-", then just copy it to s2 and move on
	if (s1[i] == '-')
		s2[ii++] = s1[i++];

	//digits
	if ((s1[i] >= 48 && s1[i] <= 57) && (s1[i+2] >= 48 && s1[i+2] <= 57) ) {
		from = s1[i];
		to = s1[i+2];
	}
	//capital letters
	else if ((s1[i] >= 65 && s1[i] <= 90) && (s1[i+2] >= 65 && s1[i+2] <= 90) ) {
		from = s1[i];
		to = s1[i+2];
	}
	//lower letters
	else if ((s1[i] >= 97 && s1[i] <= 122) && (s1[i+2] >= 97 && s1[i+2] <= 122) ) {
		from = s1[i];
		to = s1[i+2];
	}
	else {
		printf("Input \"%s\" is not valid. Plese provide an input in this form: \"a-b\"\n\n", s1);
		return -1;
	}

	//expansion
	while (from != to) {
		s2[ii++] = from;
		if (from < to)
			from++;
		else
			from--;
	}
	s2[ii++] = to;
	
	// check last char from s1
	switch(s1[i+3]) {
		case '\0':
			s2[ii] = s1[i+3];
			break;
		case '-':
			s2[ii++] = s1[i+3];
			s2[ii] = '\0';
			/* If there is other text after the "-", the switch
			 * continue until default. This is more an example of
			 * what i SHOULD NOT do with switch statements unless i
			 * want reproduce the Heartbleed bug...
			 */
			if ((s1[i+4] == '\0'))
				break;
		default:
			printf("Additional char appended to input \"%s\" will be ignored\n", s1);
			s2[ii] = '\0';

	}

	printf("\"%s\" is expanded to \"%s\"\n\n", s1, s2);
}
