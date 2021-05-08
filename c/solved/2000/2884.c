#include<stdio.h>
#include<math.h>

int main ()
{
	int n = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		int H, W, N;
		scanf("%d %d %d", &H, &W, &N);
		if(H != 1)
			printf("%d%02d\n", (N % H) ? (N % H) : H, (int)ceil((double)N / (double)H));
		else
			printf("1%02d\n", N);
	}
	
	return 0;
}
