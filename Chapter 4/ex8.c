/*Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify
getch and ungetch accordingly.*/

#include <stdio.h>	
char buf = 0;	
int getch()
{
    int c;
	if(buf != 0)
    	c = buf;
    else
        c = getchar();
    buf = 0;
    return c;
}
void ungetch(int c)
{
    if(buf != 0)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}	
int main()
{
    int c = '!';	
    ungetch(c);
    while((c=getch()) != EOF)
        putchar(c);
    return 0;
}
