#include<stdio.h>
void print(int line[],int count)
{
  printf("\n");
  for(int i=0;i<count;i++)
    printf("%c",line[i]);
  printf("\n%d\n",count);
}
int main()
{
  int c,count=1,i=0;
  int line[1000];
  while((c=getchar()) != EOF)
  {
    if(c=='\n')
    {
      if(count<80)
      {
        count=1;
	i=0;
        continue;
      }
      else
      {
        print(line,count);
        count=1;
        i=0;
      }
    }
    else
    {
      count++;
      line[i]=c;
      i++;
    }
  }
}
