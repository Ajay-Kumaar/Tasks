/*Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.
Should ungets know about buf and bufp , or should it just use ungetch ?*/

#include <stdio.h>
#include <string.h>

#define MAXBUF 100
#define MAXLINE 100

int bufp = 0;
int buf[MAXBUF];

int getch(void);
void ungetch(int c);
void ungets(char s[]);
int mgetline(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    int c;
    mgetline(line, MAXLINE);
    ungets(line);
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}

int mgetline(char s[], int lim)
{
    int i=0, c;
    for (; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
}

void ungets(char s[])
{
    int i=strlen(s);
    while (i > 0)
        ungetch(s[--i]);
}

void ungetch(int c)
{
    if (bufp >= MAXBUF)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
