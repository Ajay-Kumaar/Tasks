/*Exercise 4-13. Write a recursive version of the function reverse(s) , which reverses the
string s in place.*/

#include<stdio.h>
#include<string.h>
#define MAXLINE 1000

int getlines(char str[], int maxline)
{
	int i=0,c;
	for(; i<maxline-1 && (c=getchar()) != EOF && c != '\n'; i++)
		str[i]=c;
	if(c=='\n')
		str[i++]=c;
	str[i]='\0';
	return i;
}

void reverse(char str[], int i, int j)
{
	if(i>j)
		return ;
	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;
	reverse(str,i+=1,j-=1);
}

int main()
{
	int len=0;
	char str[MAXLINE];
	while((len=getlines(str, MAXLINE)) > 0)
	{
		reverse(str,0,len-1);
		printf(" %s\n",str);
	}
	return 0;
}
