#include<stdio.h>
void squeeze(char str1[], char str2[])
{
	int match[128]={0};
	int j=0;
    for(int i=0;str1[i] != '\0';i++)
		match[str1[i]]=1;
	for(int i=0;str2[i] != '\0';i++)
		match[str2[i]]=0;
	for(int i=0;str1[i] != '\0';i++)
	{
		if(match[str1[i]]==1)
		{
			str1[j]=str1[i];
			j++;
		}
	}
	str1[j]='\0';
	printf("%s\n",str1);
}
int main()
{
  char str1[100],str2[100];
  printf("Enter String 1: ");
  scanf("%s",str1);
  printf("Enter String 2: ");
  scanf("%s",str2);
  printf("Output: ");
  squeeze(str1,str2);
  return 0;  
}
