#include <stdio.h>
int bitcount(unsigned x)
{
    int count=0;
    for (; x!=0; x &= x - 1)
        count++;
    return count;
}
int main()
{
  unsigned int n;
  printf("Enter a number to find the no. of set bits: ");
  scanf("%u",&n);
  printf("No. of set bits: %d\n", bitcount(n));
}


