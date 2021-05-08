#include<stdio.h>
#include<string.h>

int map[10000];

int main(){
	int n = 0;
	scanf("%d", &n);
	memset(map, 0, sizeof(map));
	
	//essential init
	for(int i = 0; i < n; i++){
		int input = 0;
		scanf("%d", &input);
		map[input - 1]++;
	}
	
	for(int i = 0; i < 10000; i++){
		for(int j = 0; j < map[i]; j++)
			printf("%d\n", i + 1);
	}
	
	return 0;
}

