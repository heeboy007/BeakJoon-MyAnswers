#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

int compare(char *a, char *b){
	int len_a = strlen(a), len_b = strlen(b);
	if(len_b > len_a){
		return 1;
	}	
	else if(len_a > len_b){
		return -1;
	}
	else{
		for(int i = 0; i < len_a; i++){
			if(b[i] > a[i]){
				return 1;
			} 
			else if (a[i] > b[i]){
				return -1;
			}
		}
		return 0;
	}
}

void QuickSort(char **arr, int left, int right) {
	int L = left, R = right;
	char* temp;
	char* pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.

  //아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
	while (L <= R) {
		//pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료로 볼 수 있음.
	    while (compare(arr[L], pivot) > 0) //left부터 증가하며 pivot 이상의 값을 찾음.
			L++;
	    while (compare(arr[R], pivot) < 0) //right부터 감소하며 pivot 이하 값을 찾음.
			R--;
	    //L, R 모두 최대 pivot 위치까지 이동.
	
	    if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
	    	if (L != R) { //같지 않은 경우만.
	        	temp = arr[L];
	        	arr[L] = arr[R];
	    		arr[R] = temp;
	    	} //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
		    L++; R--; //그리고 L,R 한 칸 더 진행.
	
			/*for (int i = 0; i < 10; i++) { //데이터 확인 부분.
	    		printf("%d ", arr[i]);
	    	}
	    	printf("\n");*/
		}
	}
	//printf("\n");

	if (left < R)
		QuickSort(arr, left, R);
	if (L < right)
    	QuickSort(arr, L, right);
}

int main ()
{
	int n;
	char **words;
	scanf("%d", &n);
	
	words = malloc(sizeof(char*) * n); //pointer array
	
	for(int i = 0; i < n; i++){
		words[i] = malloc(sizeof(char) * MAX); 
		memset(words[i], 0, sizeof(words[i]));
		scanf("%s", words[i]);
	}
	
	QuickSort(words, 0, n - 1);
	
	char prev_output[MAX];
	for(int i = 0; i < n; i++){
		if(strcmp(prev_output, words[i]) != 0)
			printf("%s\n", words[i]);
		strcpy(prev_output, words[i]);
		free(words[i]);
	}
	
	free(words);
	return 0;
}
