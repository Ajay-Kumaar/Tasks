#include<stdio.h>
#include<limits.h>
#include<float.h>
int main()
{
    printf("Min Signed Char %d\n", SCHAR_MIN);
    printf("Max Signed Char %d\n", SCHAR_MAX);
    printf("Min Signed Short %d\n", SHRT_MIN);
    printf("Max Signed Short %d\n", SHRT_MAX);
    printf("Min Signed Int %d\n", INT_MIN);
    printf("Max Signed Int %d\n", INT_MAX);
    printf("Min Signed Long %ld\n", LONG_MIN);
    printf("Max signed Long %ld\n", LONG_MAX);

    printf("Max Unsigned Char %d\n", UCHAR_MAX);
    printf("Max Unsigned Short %d\n", USHRT_MAX);
    printf("Max Unsigned Int %u\n", UINT_MAX);
    printf("Max Unsigned Long %lu\n", ULONG_MAX);
    return 0;
}
