#include<stdio.h>
int main()
{
	int c,d,flag=0;
	while((c=getchar()) != EOF)
	{
	  if(c!='/' && flag==0)
		putchar(c);
	  else
	  {
		d=getchar();
		if(c=='*' && d=='/')
		{
		  flag=0;
		  //continue;
		}
		if((d=='/') || (d=='*'))
		{
	  	    while(getchar()!='\n')
		    ;
		    putchar('\n');
			flag=0;
			if(d=='*')
		      flag=1;
		}
		else if(flag==0)
		{
		  printf("%c%c",c,d);
		  flag=0;
		}  
	  }
	}
}

