#include <stdio.h>
#define MAX 1000
int get_line(char arr[], int max)
{
    int c,i=0;
    for (; i< max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        arr[i] = c;
    if(c == '\n')
	{
        arr[i] = c;
        ++i;
    }
	else
	{
        while((c = getchar() != EOF) && c != '\n')
            ++i;
        if (c == '\n')
		{
            arr[i] = c;
            ++i;
        }
    }
    arr[i] = '\0';
    return i;
}
void copy(char to[], char from[])
{
    int i=0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
int main()
{
    int len,max=0;
    char line[MAX];
    char longest[MAX];
    while ((len = get_line(line,MAX)) > 0)
	{
        if (len > max)
		{
            max = len;
            copy(longest,line);
        }
    }
    if (max > 0)
        printf("String = %s\nLength = %d\n",longest,max);
    return 0;
}
