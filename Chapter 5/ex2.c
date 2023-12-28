/*Exercise 5-2. Write getfloat , the floating-point analog of getint . What type does
getfloat return as its function value?*/

#include<stdio.h>
#include<ctype.h>
#define SIZE 1000

int getch();
void ungetch(int);
int getfloat(float* );

int main()
{
    int n;
    float array[SIZE];
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF ;n++)
        printf("\nn = %d getfloat() =  %.2f\n", n, array[n]);
    return 0;
}
int getfloat(float* pn)
{
    int c, sign;
    float power;
    while(isspace(c = getch()));
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	{
        ungetch(c);
        return -1;
    }
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getch();
    for(*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if(c == '.')
        c = getch();
    for(power = 1.0; isdigit(c); c = getch())
	{
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;
    if (c != EOF)
        ungetch(c);
    return c;
}

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
