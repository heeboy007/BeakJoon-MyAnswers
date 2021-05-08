#include<stdio.h>

int main ()
{
	int n,x;
	
	scanf("%d %d", &n, &x);
	
	for(int i = 0; i < n; i++){
		int compare;
		scanf("%d", &compare);
		if(compare < x)
			printf("%d ",compare);
	}
	
	return 0;
}
