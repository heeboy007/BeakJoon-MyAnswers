#include<stdio.h>
#include<string.h>


int main(){
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	
	int numbers[n];
	
	//essential init
	for(int i = 0; i < n; i++){
		scanf("%d", &numbers[i]);
	}
	
	int max = 0, temp = 0;
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			for(int k = j + 1; k < n; k++){
				//printf("%d / %d / %d\n", i, j, k);
				temp = numbers[i] + numbers[j] + numbers[k];
				if(temp <= m && temp > max)
					max = temp;
				
			}
		}
	}
	
	printf("%d", max);
	
	return 0;
}

