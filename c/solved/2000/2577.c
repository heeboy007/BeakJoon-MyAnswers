#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	int a = 1, b = 1, c = 1, count[10];
	char str[12];
	memset(str, 0, sizeof(str));
	memset(count, 0 , sizeof(count));
	
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	sprintf(str, "%d", a * b * c);
	
	for(int i = 0; i < strlen(str); i++){
		count[str[i] - 48]++;
	}
	
	for(int i = 0; i < 10; i++){
		printf("%d\n", count[i]);
	}
	
	return 0;
}

