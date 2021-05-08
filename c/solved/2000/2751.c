#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define BRUH 1000000

bool map[BRUH + BRUH + 1];

int main(){
	int n = 0;
	scanf("%d", &n);
	memset(map, false, BRUH + BRUH + 1);
	
	//essential init
	for(int i = 0; i < n; i++){
		int input = 0;
		scanf("%d", &input);
		map[input + BRUH] = true;
	}
	
	for(int i = -BRUH; i < BRUH + 1; i++){
		if(map[i + BRUH])
			printf("%d\n", i);
	}
	
	return 0;
}

