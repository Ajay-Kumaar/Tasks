#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void reverse(char s[])
{
    int c;
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
void itoa(int n, char s[], int w)
{
    int i=0, sign;
    if ((sign = n) < 0)
        n = -n;
    do {
        s[i++] = (n % 10) + '0';
    }while((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}
int main()
{
    int number = -123,width=8;
    char str[MAXLINE];
    printf("Integer: %d \nString: ", number);
    itoa(number, str, width);
    printf("%s\n", str);
    return 0;
}
