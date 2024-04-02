/*Exercise 8-6. The standard library function calloc (n, size) returns a
pointer to n objects of size size, with the storage initialized to zero. Write
calloc, by calling mal10cor by modifying it.*/

#include<stdio.h>
#include<stdlib.h>
void *mycalloc(unsigned n, unsigned size)
{
    unsigned i, nb = n * size;
    char *p, *q;
    if ((p = q = calloc(n, size)) != NULL)
        for (i = 0; i < nb; i++)
            *p++ = 0;
    return q;
}
int main(int argc, char *argv[])
{
    int *p = NULL;
    int i = 0;
    p = mycalloc(100, 4);
    if (p==NULL)
        printf("mycalloc returned NULL");
    else
	{
        for (i = 0; i < 100; i++)
		{
            printf("%d ", p[i]+2);
            if (i % 10 == 9)
                printf("\n");
        }
        printf("\n");
        free(p);
    }
    return 0;
}
