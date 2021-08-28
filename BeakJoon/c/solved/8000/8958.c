#include<stdio.h>
#include<string.h>

int main ()
{
	int input = 1;
	scanf("%d", &input);
	
	char arr[input][80];
	int score[input];
	
	for(int i = 0; i < input; i++){
		for(int j = 0; j < 80; j++)
			arr[i][j] = 0;
		score[i] = 0;
	}
	
	for(int i = 0; i < input; i++){
		scanf("%s", arr[i]);
		int cur_score = 0, sum_score = 0;
		for(int j = 0; j < strlen(arr[i]); j++){
			cur_score = (arr[i][j] == 'O' ? cur_score + 1 : 0);
			sum_score += cur_score;
		}
		score[i] = sum_score;
	}
	
	for(int i = 0; i < input; i++){
		printf("%d\n", score[i]);
	}
	
	return 0;
}
