#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main ()
{
	int m, n;
	
	scanf("%d %d", &m, &n);
	
	char board[m][n];
	
	for(int i = 0; i < m; i++){
		scanf("%s", board[i]);
	}
	
	int min = 33;
	for(int i = 0; i < m - 7; i++){
		for(int j = 0; j < n - 7; j++){
			int sum = 0;
			
			for(int o = 0; o < 8; o++){
				for(int p = 0; p < 8; p++){
					sum += board[i + o][j + p] == ((o + p) % 2 ? 'W' : 'B');
					//printf("[%d],[%d] s:[%d] c:[%c]\n", i + o, j + p, sum, ((o + p) % 2 ? 'W' : 'B'));
				}
			}
			sum = sum >= 32 ? 64 - sum : sum;
			min = sum < min ? sum : min;
		}
	}
	
	printf("%d", min);
	
	return 0;
}
