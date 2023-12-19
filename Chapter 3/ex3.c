#include <stdio.h>
#define MAXLINE 100
void getlines(char line[], int maxline)
{
    int i,c;
    for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
	if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
}
void expand(char s1[], char s2[])
{
    int i=0,j=0,c;
    while((c=s1[i++])!='\0')
	{
        if (s1[i]=='-' && s1[i+1]>=c)
		{
            i++;
            while(c < s1[i])
                s2[j++]=c++;
        }
		else
            s2[j++]=c;
	}
    s2[j]='\0';
}
int main()
{
    char s1[MAXLINE],s2[MAXLINE];
    getlines(s1,MAXLINE);
    expand(s1,s2);
    printf("Modified String: %s\n",s2);
    return 0;
}
