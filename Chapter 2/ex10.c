#include<stdio.h>
void lower(int ch)
{
  int upper = (ch>='A' && ch<='Z')?(ch-'A'+97):(ch);
  printf("Uppercase equivalent: %c\n",upper);
}
int main()
{
 char ch;
 printf("Enter a character to convert to lowercase: ");
 scanf("%c",&ch);
 lower(ch);
 return 0;
}
