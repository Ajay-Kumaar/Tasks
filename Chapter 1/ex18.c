#include<stdio.h>
void removews(char line[],int count)
{
  int i;
  for(i=count-1;(line[i]==' ' || line[i]=='\t');i--)
	;
  if(i==-1)
	return;
  line[i+1]='\0';
  //printf("i: %d",i);
  printf("%s\n",line);
}
int main()
{
  int c,i=0,count=0;
  char line[1000];
  while((c=getchar()) != EOF)
  {
	if(c!='\n')
	{	
	  line[i++]=c;
	  count++;
	}
	else
	{
	  removews(line,count);
	  count=0;
	  i=0;
	}
  }
  return 0;
}

/*#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int lim);

int remove_trail(char rline[]);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = _getline(line, MAXLINE)) > 0)
        if (remove_trail(line) > 0)
            printf("%s", line);

    return 0;
}

int _getline(char line[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}

/* To remove Trailing Blanks,tabs. Go to End and proceed backwards removing */
/*int remove_trail(char rline[]) {
    int i;

    for (i = 0; rline[i] != '\n'; ++i);
    --i; /* To consider raw line without \n */

   /* for (i > 0; ((rline[i] == ' ') || (rline[i] == '\t')); --i); /* Removing the Trailing Blanks and Tab Spaces */

   /* if (i >= 0) /* Non Empty Line */
   /* {
        ++i;
        rline[i] = '\n';
        ++i;
        rline[i] = '\0';
    }
    return i;
}*/
