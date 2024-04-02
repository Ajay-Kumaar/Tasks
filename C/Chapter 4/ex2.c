#include<stdio.h>
#include<ctype.h>
int getlines(char line[])
{
	int c,i;
	for(i=0;i<999 && (c=getchar()) != EOF && c!='\n';i++)
		line[i]=c;
	if(c=='\n')
		line[i++]='\n';
	line[i]='\0';
	return i;	
}
double atof(char line[])
{
	double ans=0.0,power=1.0,exp=0.0;
	int i,sign,sign2;
	for(i=0;isspace(line[i]);i++)
		;
	sign = (line[i]=='-')?-1:1;
	if(line[i]=='+' || line[i]=='-')
		i++;
	for(;isdigit(line[i]);i++)
		ans=(ans*10)+(line[i]-'0');
	if(line[i]=='.')
	{
		i++;
		for(;isdigit(line[i]);i++)
		{
			ans=(ans*10)+(line[i]-'0');
			power*=10;
		}
		ans = (ans/power);
	}
	power=1.0;
	sign2 = (line[++i]=='+')?1:-1;
	i++;
	for(;isdigit(line[i]);i++)
		exp=(exp*10)+(line[i]-'0');
	for(int j=0;j<exp;j++)
		power*=10;
	if(sign2==1)
		ans = (ans*power);
	else
		ans = (ans/power);
	return ans*sign;
}
int main()
{
	char line[1000];
	double ans=0.0;
	while(getlines(line)>0)
	{
		ans = atof(line);
		printf("%lf\n",ans);
	}
	return 0;
}
