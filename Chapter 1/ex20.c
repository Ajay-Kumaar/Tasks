#include<stdio.h>
int main()
{
  int c,count=0,tab=4;
  while((c=getchar()) != EOF)
  {
    if(c!='\t')
	{
	  putchar(c);
	  count++;
	  if(count%4==0)
	    tab+=4;
	}
	else
	{
	  for(int i=0;i<(tab-count);i++)
		printf(" ");
	  count=0;
	  tab=4;
	}
	if(c=='\n')
	{
	  count=0;
	  tab=4;
	}
  }
}
