/* Write the function _any(s1,s2), which returns the first location
 * in the string _s1_ where any character from the string _s2_ occurs, or -1 if _s1_
 * contains no characters from _s2_
 */
#include <stdio.h>

int any(char s1[], char s2[])
{
	int i, j;
	for (i=0; s1[i] !='\0'; i++) {
		for (j=0; s2[j] !='\0'; j++) {
			if (s1[i] == s2[j]) {
				return i;
			}
		}
	}
	return -1;
}

int main()
{
	char string1[] = "matching", string2[] = "this";
	printf("matching result between %s and %s = %d\n",
			string1,
			string2,
			any (string1, string2)
	      );
	char string3[] = "matching", string4[] = "rslu";
	printf("matching result between %s and %s = %d\n",
			string3,
			string4,
			any (string3, string4)
	      );

}
