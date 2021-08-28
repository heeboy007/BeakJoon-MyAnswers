#include<stdio.h>

int main(){
	int L = 0, P = 0;
	int a[5] = {0};
	scanf("%d", &L);
	scanf("%d", &P);
	for(int i = 0; i < 5; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < 5; i++){
		printf("%d ", a[i] - L * P);
	}
	return 0;
}
