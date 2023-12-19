#include<stdio.h>
#define MAXLINE 1000
void escape(char s[], char t[])
{
    int i=0,j=0;
    while (t[i] != '\0')
	{
        switch (t[i])
		{
        case '\t':
            s[j++] = '\\';
            s[j] = 't';
            break;
        case '\n':
            s[j++] = '\\';
            s[j] = 'n';
            break;
        default:
            s[j] = t[i];
            break;
        }
        i++;
        j++;
    }
    s[j] = '\0';
}
void getlines(char line[], int maxline)
{
    int i,c;
    for (i = 0; i < maxline-1 && (c = getchar()) != EOF; i++)
        line[i] = c;
    line[i] = '\0';
}
int main()
{
    char s[MAXLINE], t[MAXLINE];
    getlines(t, MAXLINE);
    escape(s, t);
    printf("Modified String: %s\n",s);
    return 0;
}
