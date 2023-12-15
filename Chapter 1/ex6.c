#include<stdio.h>
int main()
{
    int c;
    while(c=(getchar() != EOF))
	printf("\n%d",c);
    printf("\nEOF: %d\n",c);
}
