/* squeeze(s1, s2)
 * deletes each character in s1 that matches any
 * character in the _string_ s2
 */

#include <stdio.h>

void squeeze2(char s[], char c[])
{
	int i,y,j,flag;

	for (i = j = 0; s[i] != '\0'; i++) {
		for (y = flag = 0; c[y] != '\0'; y++) {
			if (s[i] == c[y]){
				flag = 1;
				break;
			}
		}
		if (!flag)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

int main ()
{
	char squeezand[] = "testingthis", squeezer[] = "est";
	printf("%s - %s\n", squeezand, squeezer);
	squeeze2(squeezand, squeezer);
	printf("= %s\n", squeezand);
}
