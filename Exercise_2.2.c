#include <stdio.h>

#define lim 80

int main()
{
	int i=0;
	int c=0;

	for (i=0; i<lim; i++)
	{
		if ((c=getchar())!='\n')
		{
			if (c!=EOF)
			{
				printf("%c\n", c);
			}
		}
	}
}
