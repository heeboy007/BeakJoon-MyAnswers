#include<stdio.h>
#include <math.h>

int main(){
	double a = 0.0, b = 0.0, v = 0.0;
	scanf("%lf %lf %lf", &a, &b, &v);
	
	printf("%d", (int)ceil((v - a) / (a - b)) + 1);
	
	return 0;
}

