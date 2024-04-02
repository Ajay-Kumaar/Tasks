#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int getlines(char *line, int max, FILE *fp);
int strindex(char *s, char *t);

char pattern[] = "ould";
int main(int argc, char* argv[])
{
    char line[MAXLINE];
	FILE *fp = fopen(argv[1],"r");
    while ((getlines(line, MAXLINE, fp)) > 0)
	{
        if (strindex(line, pattern) >= 0)
            printf("%s\n", line);
	}
	fclose(fp);
    return 0;
}
int getlines(char *s, int lim, FILE *fp)
{
    int c;
    char *t = s;
    while (--lim > 0 && (c = getc(fp)) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}
int strindex(char *s, char *t)
{
    char *b = s;
    char *p, *r;
    for (; *s != '\0'; s++)
	{
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
			;
        if (r > t && *r == '\0')
            return s - b;
    }
    return -1;
}
