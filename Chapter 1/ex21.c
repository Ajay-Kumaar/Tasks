#include<stdio.h>
#define MAX 1000
int getlines(char line[],int maxline)
{
	int c,i;
	for(i=0;i<maxline-1 && (c=getchar()) != EOF && c!='\n';i++)
		line[i]=c;
	if(c=='\n')
		line[i++]='\n';
	line[i]='\0';
	return i;
}
int main()
{
	int c,i=0,s=0;
	char line[MAX];
	while(getlines(line,MAX) > 0)
	{
		for(int i=0;line[i] != '\0';i++)
		{
			if(line[i]==' ')
				s++;
			else
			{
				if(s==0)
					putchar(c);
				else
				{
					for(int j=0;j<(s/4);j++)
						putchar('\t');
					for(int j=0;j<(s%4);j++)
						putchar(' ');
					putchar(c);
					s=0;				
				}
								
			}
		}
	}
	return 0;
}
