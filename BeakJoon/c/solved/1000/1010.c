#include<stdio.h>

int main ()
{
	int input = 0, n = 0, m = 0, output = 1;
	int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int cur_num[10] = {0};
	
	scanf("%d", &input);
	
	for(int i = 0; i < input; i++){
		scanf("%d %d", &n, &m);
		
		for(int j = m; j > (m - n > n ? m - n : n); j--){
			int cur = j;
			for(int k = 0; k < 10; k++){
				while(cur % primes[k] == 0 && cur != 1){
					cur /= primes[k];
					cur_num[k] += 1;
				}
			}
		}
		
		for(int j = 1; j < 1 + (m - n > n ? n : m - n); j++){
			int cur = j;
			for(int k = 0; k < 10; k++){
				while(cur % primes[k] == 0 && cur != 1){
					cur /= primes[k];
					cur_num[k] -= 1;
				}	
			}
		}
			
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < cur_num[j]; k++)
				output *= primes[j];
			cur_num[j] = 0;
		}
		printf("%d\n", output);
		output = 1;
	}
	return 0;
}

