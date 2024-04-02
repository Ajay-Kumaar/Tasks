#include<stdio.h>
#include<string.h>
#include<math.h>
int conversion(char str[])
{
   int y=0,ans=0,x=0;
   for(int i=strlen(str)-1;i>=0;i--)
   {
      if(str[i]>='0' && str[i]<='9')
	  {
         x = str[i]-'0';
      }
      else if(str[i]>='A' && str[i]<='Z')
	  {
         x = str[i]-'A'+10;
      }
	  else
	  {
		 x = str[i]-'a'+10;
	  }
      ans+=(x*pow(16,y));
	  y++;
   }
   return ans;
}
int main()
{
   char str[100]; 
   printf("Enter the Hexadecimal number: ");
   scanf("%s",str);
   printf("Decimal: %d", conversion(str));
   return 0;
}
