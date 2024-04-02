#include <stdio.h>
#define MAXLINE 1000
char pattern[] = "abc";
int getlines(char line[], int limit)
{
	int c, i=0;
	while (--limit > 0 && (c=getchar()) != EOF && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}
int strindex(char s[], char t[])
{
	int i, j, k, pos=-1;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			pos=i;
	}
	printf("Pos: %d\n",pos);
}
int main()
{
	char line[MAXLINE];
	while (getlines(line, MAXLINE) > 0)
		strindex(line, pattern);
	return 0;
}
