/* Add access to library functions like sin, exp and pow. See
 * <math.h> in Appendix B, Section 4.
 */

#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <math.h>

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define MAXVAL 100	/* maximum depth of val stack */

int getop(char []);
void push(double);
double pop(void);
double printtop (void);
void duplicate (void);
void swap (void);
void clear (void);

int sp = 0;
double val[MAXVAL];	/* value stack */

/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			push((int)pop() % (int)op2);
			break;
		case 'p':
			printf("top of stack: %g\n", printtop());
			break;
		case 'd':
			duplicate();
			break;
		case 's':
			swap();
			break;
		case 'c':
			clear();
			break;
		case 'q':
			push(sin(pop()));
			break;
		case 'w':
			push(exp(pop()));
			break;
		case 'e':
			op2 = pop();
			push(pow(op2,pop()));
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error:stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop (char s[])
{
	int i,c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
			;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	/* not a number */
	i = 0;
	if ((c == '-') && !(isdigit(s[++i] = c = getch()))) { /* collect sign */
		if (c != EOF)
			ungetch(c);
		return '-';
	}
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getch(void)			/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push caracter back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

double printtop (void)		/* output the value in the top position */
{
	if (sp > 0)
		return val[sp];
	else {
		printf("error:stack empty\n");
		return 0.0;
	}
}

void duplicate (void)		/* duplicates the value in the top position */
{
	double aux;

	aux = pop();
	push(aux);
	push(aux);

}

void swap (void)		/* swap the 2 values in the top position */
{
	double aux1, aux2;
	aux1 = pop();
	aux2 = pop();
	push(aux1);
	push(aux2);
}

void clear (void)		/* clear the stack */
{
	double aux;
	while (sp > 0)
		pop();
}
