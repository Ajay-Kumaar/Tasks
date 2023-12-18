#include<stdio.h>
void squeeze(char str1[], char str2[])
{
  for(int i=0;str1[i] != '\0';i++)
  {
	for(int j=0;str2[j] != '\0';j++)
	{
		if(str1[i]==str2[j])
		{
			str1[i]=str1[i+1];
			continue;
		}
	}
  }
  printf("Final String: %s",str1);
}
int main()
{
  char str1[100],str2[100];
  printf("Enter String 1: ");
  scanf("%s",str1);
  printf("Enter String 2: ");
  scanf("%s",str2);
  squeeze(str1,str2);
  return 0;
}
