#include <stdio.h>
int main()
{
int b=0,t=0,n=0;
int c;
while((c = getchar()) != EOF){
  if(c == ' ')
    ++b;
  else if(c == '\t')
    ++t;
  else if(c == '\n')
    ++n; 
  }
printf("%d %d %d\n",b,t,n);
}

