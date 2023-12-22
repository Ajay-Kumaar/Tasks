#include<stdio.h>
#define MAX 100
int getlines(char line[],int maxline)
{
	int c,i;
	for(i=0;i<maxline-1 && (c=getchar()) != EOF && c!='\n';i++)
		line[i] = c;
	if(c=='\n')
		line[i++]='\n';
	line[i]='\0';
	return i;
}
int main()
{
	char line[MAX];
	int i,length=0,fl=10;
	while((length=getlines(line,MAX)) > 0)
	{
		for(i=0;line[i] != '\0';i++)
		{
			if(i<fl)
				putchar(line[i]);
			else
			{
				fl+=10;
				putchar('\n');
				putchar(line[i]);
			}
		}
		fl=10;
	}
	return 0;
}
