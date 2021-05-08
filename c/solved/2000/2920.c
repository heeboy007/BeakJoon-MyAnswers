#include<stdio.h>
#include<stdbool.h>

int main ()
{
	int input = 0;
	bool flag = true;
	
	scanf("%d", &input);
	if(input == 1){
		for(int i = 2; i <= 8; i++){
			scanf("%d", &input);
			if(input != i)
				flag = false;
		}
		if(flag)
			printf("ascending");
		else
			printf("mixed");
	} else if(input == 8){
		for(int i = 7; i >= 1; i--){
			scanf("%d", &input);
			if(input != i)
				flag = false;
		}
		if(flag)
			printf("descending");
		else
			printf("mixed");
	} else { //mixed
		for(int i = 2; i <= 9; i++){
			scanf("%d", &input);
		}
		printf("mixed");
	}
	
	return 0;
}

