#include<stdio.h>
#include<stdlib.h>

int Euclidean(int a, int b)
{
	return a%b ? Euclidean(b, a%b) : b;
}

int main(){
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);
	int n = Euclidean(a,b);
	printf("%d %d", n, a * b / n);
	return 0;
}
