#include<stdio.h>

void any(char str1[], char str2[])
{
for(int i=0;str1[i]!='\0';i++)
{
	for(int j=0;str2[j]!='\0';j++)
	{
		if(str1[i]==str2[j])
		{
			printf("First location: %d",i);
			return;
		}
	}
}
printf("Status: -1");
}

int main()
{
  char str1[100],str2[100];
  printf("Enter two strings: ");
  scanf("%s %s",str1,str2);
  any(str1,str2);
  return 0;
}
