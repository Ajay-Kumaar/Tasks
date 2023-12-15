#include<stdio.h>
void temp_conversion(){
  for(int f=100;f>=0;f-=10)
	printf("%d - %.2f\n",f,((5.0/9.0)*(f-32)));
}
int main()
{
    printf("Temperature conversion program: Fahrenheit - Celsius\n\n");
    temp_conversion();
}
