#include <stdio.h>
int wordlength()
{
    int i;
    unsigned v = (unsigned)~0;
    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
unsigned rightrotation(unsigned x, int n)
{
    unsigned rbit = x << (wordlength()-n);
    x = x >> n;
    x = x | rbit;
    return x;
}
int main()
{
    printf("%u\n",(unsigned)rightrotation((unsigned)44,2));
    return 0;
}
