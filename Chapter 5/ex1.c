/*Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid
representation of zero. Fix it to push such a character back on the input.*/

#include<stdio.h>
#include<ctype.h>

#define SIZE 1000
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
	{
        ungetch(c);
        return -1;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    if (!isdigit(c))
        return -1;
	*pn = 0;
	while(isdigit(c))
	{
        *pn = (*pn * 10) + (c - '0');
		c=getch();
	}
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
int main()
{
    int n, array[SIZE];
    for (n = 0; n < SIZE && getint(&array[n]) != EOF ;n++)
        printf("\nn = %d getint() =  %d\n", n, array[n]);
    return 0;
}
