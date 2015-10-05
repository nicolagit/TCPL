#include <stdio.h>
#include <string.h>

#define MAXSTRING 999

void checkunbalanced(char input[]);

main() {
	char input[MAXSTRING];
	int c=0;
	int i=0;

	while ((c=getchar())!=EOF && c!='\0' && c!='\n') {
		input[i]=c;
		++i;
	}
	input[i]='\0';

	checkunbalanced(input);
		return 0;
}

/*
 * Check for unbalanced parenthesis (open but not closed)
 */
void checkunbalanced(char in[]) {
	char begin[] = {'(','[','{'};
	char end[] = {')',']','}'};
	int i=0;
	int ii=0;
	int numOfElements = sizeof(begin)/sizeof(begin[0]);
	char status[numOfElements];

	for (i=0; i<numOfElements; i++) {
		status[i] = 0;
	}
	status[numOfElements] = '\0';

	for (i=0; in[i]!='\0'; i++) {
		for (ii=0; ii<numOfElements; ii++) {
			if ((in[i]==begin[ii]) && (status[ii] == 0)) {
				status[ii]=begin[ii];
			}
			else if ((in[i]==begin[ii]) && (status[ii] != 0)) {
				printf("found an extra %c\n", in[i]);
			}
			else if ((in[i]==end[ii]) && (status[ii] == begin[ii])) {
				status[ii]=0;
			}
			else if ((in[i]==end[ii]) && (status[ii] == 0)) {
				printf("missing the opening %c\n", in[i]);
			}

		}
	}
}
