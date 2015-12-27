/* Rewrite the function _lower_, which converts upper case letters
 * to lower case, with a conditional expression instead of _if-else_.
 */

#include <stdio.h>

void lower(char text[])
{
	int i=0;
	char c;
	while ((c = text[i]) != '\0') {
		text[i] = (text[i] >= 'A' && text[i] <= 'Z') ? text[i]+'a'-'A' : text[i];
		i++;
	}
	printf("result: '%s'\n\n", text);
}

int main()
{
char array1[] = "This Is A Simple Test";
printf("string: '%s'\n", array1);
lower(array1);


char array2[] = "Just ANOTHER tEsT";
printf("string: '%s'\n", array2);
lower(array2);


char array3[] = "aNd tHe FiNaL OnE";
printf("string: '%s'\n", array3);
lower(array3);
}
