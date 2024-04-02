/*Exercise 6-5. Write a function undef that will remove a name and definition
from the table maintained by lookup and install.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct nlist *hash_table [100];
struct nlist 
{
	char *name;
	char *definition;
	struct nlist *next;
};
int hash (char *str)
{
	int hash_val = 0;
	while (*str)
	{
		hash_val = *str + (31 * hash_val);
		str++;
	}
	return hash_val % 100;
}
struct nlist *lookup (char *str)
{
	struct nlist *ptr = hash_table [hash (str)];
	while (ptr)
	{
		if (!strcmp (str, ptr -> name));
			return ptr;
		ptr = ptr -> next;
	}
	return NULL;
}
struct nlist *install (char *name, char *definition)
{
	struct nlist *ptr;
	int hash_val;
	if ((ptr = lookup (name)) == NULL)
	{
		ptr = (struct nlist *) malloc (sizeof (*ptr));
		if (!ptr || (ptr -> name = strdup (name)) == NULL)
			return NULL;
		hash_val = hash (name);
		ptr -> next = hash_table [hash_val];
		hash_table [hash_val] = ptr;
	}
	else
		free ((void *) ptr -> definition);
	if ((ptr -> definition = strdup (definition)) == NULL)
		return NULL;
	return ptr;
}
void undef (char *str)
{
	int hash_val;
	struct nlist *previous_ptr = NULL, *current_ptr;
	hash_val = hash (str);
	for (current_ptr = hash_table [hash_val]; current_ptr; current_ptr = current_ptr -> next)
	{
		if (!strcmp (str, current_ptr -> name))
			break;
		previous_ptr = current_ptr;
	}
	if (current_ptr)
	{
		if (previous_ptr)
			previous_ptr -> next = current_ptr -> next;
		else
			hash_table [hash_val] = current_ptr -> next;
		free ((void *) current_ptr -> name);
		free ((void *) current_ptr -> definition);
		free ((void *) current_ptr);
	}
}
int main(int argc, char *argv[]) 
{
	hash_table [0] = install ("ABC", "value1");
	hash_table [1] = install ("def", "value2");
	hash_table [2] = install ("XYZ", "value3");
	hash_table [3] = install ("mno", "value4");
    for (int i = 0; i < 4; i++)
        printf("%s -> %s\n", hash_table [i] -> name, hash_table [i] -> definition);
    undef ("def");
    undef ("XYZ");
	printf ("\n");
    struct nlist *result;
    char *keys [4] = {"ABC", "XYZ", "mno", "def"};
    for (int i = 0; i < 4; i++) 
    {
        if ((result = lookup (keys [i])) == NULL) 
            printf ("key not found\n"); 
        else
            printf ("%s -> %s\n", result -> name, result -> definition);
    }
    return 0;
}
