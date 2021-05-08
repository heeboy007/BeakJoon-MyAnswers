#include<stdio.h>
#include<unistd.h>

int main(){
	int n = 0, max = 0;
	float avg = 0.0;
	
	scanf("%d", &n);
	
	int scores[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d", &scores[i]);
		if(scores[i] > max)
			max = scores[i];
	}
	
	for(int i = 0; i < n; i++){
		avg += (float)scores[i] / (float)max * 100.0f; 
	}
	avg /= (float)n; 
	
	printf("%f", avg);
	
	return 0;
}
