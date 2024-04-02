#include <stdio.h>
int main()
{
int c,count=0;
while ((c = getchar()) != EOF)
 {
  if(c != ' ' && c != '\n' && c != '\t')
  {
    putchar(c);
    count++;
  }
  else
  {
    printf("----- %d\n",count);
    count=0;
  }
 }
}
