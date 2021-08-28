#include<stdio.h>

int main ()
{
	char a[3], b[3];
	int n_a, n_b;
	scanf("%s %s", a, b);
	
	char ch = a[0];
	a[0] = a[2];
	a[2] = ch;
	
	ch = b[0];
	b[0] = b[2];
	b[2] = ch;
	
	n_a = (a[0] - 48) * 100 + (a[1] - 48) * 10 + (a[2] - 48);
	n_b = (b[0] - 48) * 100 + (b[1] - 48) * 10 + (b[2] - 48);
	
	printf("%d", n_a > n_b ? n_a : n_b);
	
	return 0;
}
