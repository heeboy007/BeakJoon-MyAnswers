#include<stdio.h>

int main ()
{
	double a = 3.0L, b = 3.0L;
	
	scanf("%lf", &a);
	scanf("%lf", &b);
	
	printf("%.15lf, %.15lf, %.15lf", a, b, a / b);
	return 0;
}
