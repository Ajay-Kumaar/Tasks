/*Exercise 6-2. Write a program that reads a C program and prints in alphabeti-
cal order each group of variable names that are identical in the first 6 charac-
ters, but different somewhere thereafter. Don't count words within strings and
comments. Make 6 a parameter that can be set from the command line*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
struct tree_node
{
	char *word;
	int match;
	struct tree_node *left, *right;
};
char buffer [1000];
int buffer_ptr = 0;
int getch() 
{
    return (buffer_ptr > 0) ? buffer [--buffer_ptr] : getchar ();
}
void ungetch (int c) 
{
    if (buffer_ptr >= 1000)
        printf ("ungetch: Printing too many characters\n");
    else
        buffer [buffer_ptr++] = c;
}
struct tree_node *talloc ()
{
	return (struct tree_node *)malloc (sizeof (struct tree_node));
}
int comment ()
{
	int c;
	while ((c = getch ()) != EOF)
		if (c == '*')
			if ((c = getch ()) == '/')
				break;
			else
				ungetch (c); 
		else if (c == '/')
		{
			while ((c = getch ()) != '\n');
			break;
		}
		
		return c;
}
int getword (char *word, int limit)
{
	int c, d;
	char *word_ptr = word;
	while (isspace (c = getch ()));
	if (c != EOF)
		*word_ptr++ = c;
	if (isalpha (c) || c == '_' || c == '#')
	{
		for (; --limit; word_ptr++)
			if (!isalnum (*word_ptr = getch ()) && *word_ptr != '_')
			{
				ungetch (*word_ptr);
				break;
			}
	}
	else if (c == '\'' || c == '"')
	{
		for (; --limit; word_ptr++)
			if ((*word_ptr = getch ()) == '\\')
				*++word_ptr = getch ();
			else if (*word_ptr == c)
			{
				word_ptr++;
				break;
			}
			else if (*word_ptr == EOF)
				break;
	}
	else if (c == '/')
	{
		if ((d = getch ()) == '*')
			c = comment ();
		else if (d == '/')
			while ((c = getch ()) != '\n');
		else
			ungetch (d);
	}
	*word_ptr = '\0';
	return c;
}
void treexprint (struct tree_node *ptr)
{
	if (ptr)
	{
		treexprint (ptr -> left);
		if (ptr -> match)
			printf ("%s\n", ptr -> word);
		treexprint (ptr -> right);
	}
}
int compare (char *str, struct tree_node *ptr, int number, int *found)
{
	int i;
	char *t = ptr -> word;
	
	for (i = 0; *str == *t; i++, str++, t++)
		if (*str == '\0')
			return 0;
			
	if (i >= number)
	{
		*found = 1;
		ptr -> match = 1;
	}
	
	return *str - *t;
}
struct tree_node *addtreex (struct tree_node *ptr, char *word, int number, int *found)
{
	int condition;
	
	if (!ptr)
	{
		ptr = talloc ();
		ptr -> word = strdup (word);
		ptr -> match = *found;
		ptr -> left = ptr -> right = NULL;
	}
	else if ((condition = compare (word, ptr, number, found)) < 0)
		ptr -> left = addtreex (ptr -> left, word, number, found);
	else if (condition > 0)
		ptr -> right = addtreex (ptr -> right, word, number, found);
	return ptr;
}
int main (int argc, char *argv [])
{
	struct tree_node *root;
	char word [100];
	int found = 0;
	int number = (--argc && (*++argv)[0] == '-') ? atoi (argv [0] + 1) : 6;
	root = NULL;
	while (getword (word, 100) != EOF)
	{
		if (isalpha (word [0]) && strlen (word) >= number)
			root = addtreex (root, word, number, &found);
		found = 0;
	}
	printf ("Printing tree nodes:\n");
	treexprint (root);
	return 0;
}
