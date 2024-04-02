#include <stdio.h>
int main()
{
int c, nl, nw, nc, flag=0;
nl = nw = nc = 0;
while ((c = getchar()) != EOF){
  nc++;
  if (c == '\n')
    nl++;
  if (c != ' ' && c != '\n' && c != '\t')
    flag=0;
  else if(flag==0){
    nw++;
    flag=1;
  }
}
printf("\n%d %d %d\n", nl, nw, nc);
}
