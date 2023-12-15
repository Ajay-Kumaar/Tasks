#include<stdio.h>
int main()
{
    int f;
    printf("Temperature conversion program: Fahrenheit - Celsius\n\n");
    for(f=0;f<=100;f+=10)
	printf("%d - %.2f\n",f,((5.0/9.0)*(f-32)));
}
