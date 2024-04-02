#include<stdio.h>
void reverse(int line[],int count)
{
  printf("\n");
  for(int i=count-1;i>=0;i--)
  	printf("%c",line[i]);
  printf("\n");
}
int main()
{
  int c,count=1,i=0;
  int line[1000];
  while((c=getchar()) != EOF)
  {
    if(c!='\n')
	{
	  line[i]=c;
	  i++;
	  count++;
	}
	else
	{
	  reverse(line,count);
	  i=0;
	  count=1;
	}
  }
}
