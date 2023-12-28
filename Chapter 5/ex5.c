#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int mystrnlen(char *s)
{
    char *p = s;
    while (*s != '\0')
        s++;
    return s-p;
}
void strcatt(char* s1,char* s2,int n)
{
	while(*s1 != '\0')
		s1++;
	for(int i=0;i<n;i++)
	{
		*s1++ = *s2++;
		if(*s2 == '\0')
			break;
	}
	*s1='\0';
}
void strcpyy(char* s1,char* s2,int n)
{
    for(int i=0;i<n && *s2 != '\0';i++)
	{
		*s1++ = *s2++;
	}
}
int strcmpp(char* s1,char* s2,int n)
{
    for(int i=0;i<n;i++)
	{
		if(*s1 != *s2)
			return (*s1-*s2);
		if(*s1 == '\0')
			return 1;
		s1++;
		s2++;
	}
	return 1;
}
int main()
{
    char source[] = "ABCDE";
    char dest[] = "FGHIJFGHIJKLMNOPQRSTUVWXYZ";
    strcpyy(dest, source, 5);
    printf("\nstrcpy: %s\n", dest);
    char s1[] = "abcdefghij";
    char t1[] = "abcd";
    strcatt(s1, t1, 5);
    printf("\nstrcat: %s\n", s1);
    char s2[] = "ABCDE";
    char t2[] = "ABCDEFGH";
    int result = strcmpp(s2, t2, 5);
    printf("\nstrcmp: %d\n", result);
    return 0;
}
