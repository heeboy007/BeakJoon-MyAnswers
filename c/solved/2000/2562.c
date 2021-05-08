#include<stdio.h>

int main ()
{
	int max = 0, ind = 1, input = 0;
	scanf("%d", &input);
	max = input;
	
	for(int i = 2; i <= 9; i++){
		scanf("%d", &input);
		ind = max < input ? i : ind;
		max = max < input ? input : max;
	}
	printf("%d\n%d", max, ind);
	return 0;
}
