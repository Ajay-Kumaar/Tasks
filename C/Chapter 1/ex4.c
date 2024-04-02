#include<stdio.h>
int main()
{
    int c;
    printf("Temperature conversion program: Celsius - Fahrenheit\n\n");
    for(c=0;c<=100;c+=10)
	printf("%d - %.2f\n",c,((c*(9.0/5.0))+32));
}
