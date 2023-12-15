#include <stdio.h>
int main()
{
int c,count=0,arr[256]={0};
while ((c = getchar()) != EOF)
 {
  //if(c != ' ' && c != '\n' && c != '\t')
    arr[c]++;
 }
for(int i=0;i<256;i++)
{
  if(arr[i]>0)
    printf("ASCII %d:  %c - %d\n",i,i,arr[i]);
}
}
