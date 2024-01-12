#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_BYTES (unsigned)10240
#define NALLOC 1024

typedef long Align;
union header 
{
	struct {
		union header *ptr;
		unsigned size;
	} s;
	Align x;
};

typedef union header Header;
static unsigned max_alloc_units;
static Header base;
static Header *free_ptr = NULL;					

static Header *morecore (unsigned number_of_units)
{
	char *cp;
	Header *up;
	
	if (number_of_units < NALLOC)
		number_of_units = NALLOC;
		
	cp = sbrk (number_of_units * sizeof (Header));
	if (cp == (char *) - 1)
		return NULL;
		
	up = (Header *) cp;
	up -> s.size = number_of_units;
	max_alloc_units = (up -> s.size > max_alloc_units) ? up -> s.size : max_alloc_units;
	free ((void *) (up + 1));
	
	return free_ptr;
}
void* mymalloc (unsigned number_of_bytes)
{
	Header *ptr, *prev_ptr;
	unsigned number_of_units;
	if (number_of_bytes > MAX_BYTES)
	{
		fprintf (stderr, "Can't allocate more than %u bytes\n", MAX_BYTES);
		return NULL;
	}
	number_of_units = (number_of_bytes + sizeof (Header) - 1) / sizeof (Header) + 1;
	if ((prev_ptr = free_ptr) == NULL)
	{
		base.s.ptr = free_ptr = prev_ptr = &base;
		base.s.size = 0;
	}
	for (ptr = prev_ptr -> s.ptr; ; prev_ptr = ptr, ptr = ptr -> s.ptr)
	{
		if (ptr -> s.size >= number_of_units)
		{
			if (ptr -> s.size == number_of_units)
				prev_ptr -> s.ptr = ptr -> s.ptr;
			else
			{
				ptr -> s.size -= number_of_units;
				ptr += ptr -> s.size;
				ptr -> s.size = number_of_units;
			}
			free_ptr = prev_ptr;
			return (void *)(ptr + 1);
		}
		if (ptr == free_ptr)
			if ((ptr = morecore (number_of_units)) == NULL)
				return NULL;
	}
}
int main ()
{
	int *ptr = mymalloc (100000);
	if (ptr!=NULL)
	{
		printf ("Allocated space\n");
		free (ptr);
	} 
	else
		printf ("Not enough space\n");
	return 0;
}
