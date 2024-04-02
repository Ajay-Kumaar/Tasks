/*Exercise 5-4. Write the function strend(s,t) , which returns 1 if the string t occurs at the
end of the string s , and zero otherwise.*/

#include<stdio.h>
#define MAXLINE 1000

int strend(char* s,char* t)
{
	char* u = t;
	while(*s != '\0')
	{
		if(*s == *t)
			t++;
		else
			t=u;
		s++;
	}
	if(*s == '\0' && *t == '\0')
		return 1;
	return 0;
}
void getlines(char s[],int maxline)
{
    int c, i;
    for(i = 0; i < maxline - 1 && ((c = getchar()) != EOF) && c != '\n'; i++)
        s[i] = c;
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
}
int main()
{
    char s[MAXLINE],t[MAXLINE];
    getlines(s,MAXLINE);
    getlines(t,MAXLINE);
    int result = strend(s,t);
    printf("\nResult: %d\n",result);
    return 0;
}
