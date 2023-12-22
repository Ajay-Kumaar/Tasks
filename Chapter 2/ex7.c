#include<stdio.h>
unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n));
}
int main()
{
	unsigned int x = 18;
	printf("Inverted value: %u",invert(x,2,2));
	return 0;
}
