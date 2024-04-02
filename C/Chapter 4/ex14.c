/*Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t .
(Block structure will help.)*/

#include<stdio.h>
#define swap(data_type,x,y) { data_type temp = x; \
										   x = y; \
										   y = temp; }
int main()
{
    int x = 1, y = 2;
    printf("x = %d y = %d\n",x,y);
    swap(int,x,y);
    printf("x = %d y = %d\n",x,y);
}
