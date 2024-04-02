/*Exercise 7-4. Write a private version of scanf analogous to minprintf from the previous
section.*/

#include <stdarg.h>
#include <stdio.h>
void minscanf(char *fmt, ...)
{
    va_list ap;
    char *p, *sval;
    int *ival;
    float *dval;
    va_start(ap, fmt);
    for (p = fmt; *p; p++)
	{
        if (*p != '%')
            continue;
		p++;
        switch (*p)
		{
            case 'd':
                ival = va_arg(ap, int *);
                char *d = "44";
                sscanf(d, "%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, float *);
                char *f = "5.33";
                sscanf(f, "%f", dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                sscanf("test_char", "%s", sval);
                break;
            case 'o':
                ival = va_arg(ap, int *);
                char *o = "011";
                sscanf(o, "%o", ival);
                break;
            case 'x':
                ival = va_arg(ap, int *);
                char *x = "1a";
                sscanf(x, "%x", ival);
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}
int main()
{
    int i;
    minscanf("%d", &i);
    printf("minscanf input: %d\n", i);
    char *a;
    minscanf("%s", a);
    printf("minscanf input: %s\n", a);
    float f;
    minscanf("%f", &f);
    printf("minscanf input: %f\n", f);
    int o;
    minscanf("%o", &o);
    printf("minscanf input in octal %o, in decimal %d\n", o, o);
    int x;
    minscanf("%x", &x);
    printf("minscanf input in hex %x, in decimal %d\n", x, x);
    return 0;
}
