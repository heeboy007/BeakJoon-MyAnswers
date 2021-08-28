#include<stdio.h>

// answer to life, universe and everything is FOURTY - TWO

int main(){
	
	int remainder[10], i;
	
	for(i = 0; i < 10; i++){
		remainder[i] = 43;
		int input = 0;
		scanf("%d", &input);
		input %= 42;
		for(int j = 0; j <= i; j++){
			if(remainder[j] == input){
				break;
			}
			else if(remainder[j] == 43){
				remainder[j] = input;
				break;
			}	
		}
	}
	
	for(i = 0; i < 10; i++){
		if(remainder[i] == 43)
			break;
	}
	
	printf("%d", i);
	
	return 0;
}

