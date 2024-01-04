/*Exercise 7-9. Functions like isupper can be implemented to save space or to save time.
Explore both possibilities.*/

#include <stdio.h>
#include <stdlib.h>
int myisupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}
int main()
{
    int c;
    while ((c = getchar()) != EOF)
	{
        if (c == '\n')
            continue;
        if (myisupper(c) == 1)
            printf("True\n");
        else
            printf("False\n");
    }
    return 0;
}
