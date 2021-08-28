#include<stdio.h>

int main ()
{
	int n = 0, max = 0, min = 0, input = 0;
	
	scanf("%d", &n);
	scanf("%d", &max);
	min = max;
	
	for(int i = 0; i < n - 1; i++){
		scanf("%d", &input);
		max = (input > max ? input : max);
		min = (input < min ? input : min);
	}
	
	printf("%d %d", min, max);
	return 0;
}

