#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int getch(void);
void ungetch(int);
int getop(char[], FILE*);
void push(double);
double pop(void);

int main(int argc, char* argv[])
{
    int type;
    double op2;
    char s[MAXOP];
	FILE *fp = fopen(argv[1],"r");
    while ((type = getop(s, fp)) != EOF)
	{
        switch (type)
		{
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
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
	fclose(fp);
    return 0;
}

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    else
	{
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[], FILE *fp)
{
	int i;
	char c;
    while ((c=getc(fp)) != EOF)
    {
    	if((s[0]=c) != ' ' && c != '\t')
    		break;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    i = 0;
    if (c == '-' || isdigit(c))
    {
        while ((c=getc(fp)))
        {
        	if(!(isdigit(s[++i] = c)))
        		break;
        }
    }
    if (c == '.')
    {
    	while ((c=getc(fp)))
        {
        	if(!(isdigit(s[++i] = c)))
        		break;
        }
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getch()
{
 return (bufp > 0) ? buf[--bufp] : getchar();
}
