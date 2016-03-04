/* Add commands for handling variables. (It's easy to provide
 * twenty-six variables with single-letter names.) Add a variable for the most
 * recently printed values.
 */

#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <math.h>

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define MAXVAL 100	/* maximum depth of val stack */
#define MAXREC 26	/* maximum number of variable memories */

int getop(char []);
void push(double);
double pop(void);
double printtop (void);
void duplicate (void);
void swap (void);
void clear (void);
void store (char);
double load (char);

int sp = 0;
double val[MAXVAL];	/* value stack */
char record[MAXREC];	/* memories for variable */

/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:	/* add number to stack */
			push(atof(s));
			break;
		case '+':	/* sum */
			push(pop() + pop());
			break;
		case '*':	/* multiply */
			push(pop() * pop());
			break;
		case '-':	/* subtract */
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':	/* divide */
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':	/* modulus */
			op2 = pop();
			push((int)pop() % (int)op2);
			break;
		case '!':	/* print top of stack */
			printf("top of stack: %g\n", printtop());
			break;
		case '@':	/* duplicate */
			duplicate();
			break;
		case '#':	/* swap */
			swap();
			break;
		case '&':	/* clear stack */
			clear();
			break;
		case '(':	/* sine */
			push(sin(pop()));
			break;
		case '^':	/* base-e exponential */
			push(exp(pop()));
			break;
		case ')':	/* power function */
			op2 = pop();
			push(pow(op2,pop()));
			break;
		case '=':	/* load top value to a variable */
			load();
			break;
		case 'isascii(number)':	/* store */
			store(number);
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

void store (char var)	/* store value from top of stack to variable */
{
	record[var-'a'] = pop();
}

double load (char var)		/* load the value of a variable */
{
	return record[var-'a'];
}
