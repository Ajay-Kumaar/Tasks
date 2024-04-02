#include <stdio.h>
#include <string.h>
#define MAXLINE 100

void reverse(char s[])
{
    int c;
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
void itob(int n, char s[], int b)
{
    int i=0,j,sign;
    if ((sign = n) < 0)
        n = -n;
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
int main()
{
    int number=42425,base=16;
    char str[MAXLINE];
    itob(number,str,base);
    printf("%s\n",str);
    return 0;
}
