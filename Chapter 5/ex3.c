#include<stdio.h>
#define MAXLINE 1000

void getlines(char line[],int maxline)
{
    int c, i;
    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if(c == '\n')
        line[i++] = c;
    line[i] = '\0';
}
void mystrcat(char* s,char* t)
{
	while(*s != '\0')
        s++;
    s--;
    while((*s = *t) != '\0')
	{
        s++;
        t++;
    }
}
int main()
{
    char s[MAXLINE],t[MAXLINE];
    getlines(s,MAXLINE);
    getlines(t,MAXLINE);
	printf("\ns: %s\nt: %s",s,t);
    mystrcat(&s[0],&t[0]);
    printf("\nConcatenated string: %s\n",s);
    return 0;
}
