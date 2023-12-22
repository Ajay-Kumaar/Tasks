#include <stdio.h>
#define MAXLINE 1000
char line[MAXLINE];
int getlines()
{
 int c,i;
 extern char line[];
 for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  line[i] = c;
 if (c == '\n')
  line[i] = c;
 line[i] = '\0';
 return i;
}
int main()
{
 int len = 0,t = 0,cb = 0, p = 0, sb = 0,s_quotes = 1, d_quotes = 1;
 while ((len = getlines()) > 0)
 {
   t = 0;
   while (t < len)
   {
   if (line[t] == '{')
    cb++;
   if (line[t] == '}')
    cb--;
   if (line[t] == '[')
    sb++;
   if (line[t] == ']')
    sb--;
   if (line[t] == '(')
    p++;
   if (line[t] == ')')
    p--;
   if (line[t] == '\'')
    s_quotes *= -1;
   if (line[t] == '\"')
    d_quotes *= -1;
   t++;
    }
 }
 if (d_quotes != 1)
 	printf("Mismatch in double quote mark");
 if (s_quotes != 1)
 	printf("Mismatch in single quote mark");
 if (p != 0)
 	printf("Mismatch in parenthesis");
 if (cb != 0)
 	printf("Mismatch in curly braces");
 if (sb != 0)
 	printf("Mismatch in square bracket mark");
 if (sb == 0 && cb == 0 && p == 0 && s_quotes == 1 && d_quotes== 1)
 	printf("Correct syntax\n");
 return 0;
}
