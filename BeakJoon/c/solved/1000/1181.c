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
	char* pivot = arr[(left + right) / 2]; //�Ǻ� ��ġ(�߾�)�� ���� ����.

  //�Ʒ��� while���� ���Ͽ� pivot �������� ��, �� ũ�� ���� �� ����. = Partition
	while (L <= R) {
		//pivot�� �߰� ���̰�, �� ��� arr[L], arr[R]�� pivot�� ���ϴ� �߰� ������ �Ѿ�� ����� �� �� ����.
	    while (compare(arr[L], pivot) > 0) //left���� �����ϸ� pivot �̻��� ���� ã��.
			L++;
	    while (compare(arr[R], pivot) < 0) //right���� �����ϸ� pivot ���� ���� ã��.
			R--;
	    //L, R ��� �ִ� pivot ��ġ���� �̵�.
	
	    if (L <= R) { //���� L�� R���ϸ�. (���� : L>R �κ��� �̹� ������ �� ������).
	    	if (L != R) { //���� ���� ��츸.
	        	temp = arr[L];
	        	arr[L] = arr[R];
	    		arr[R] = temp;
	    	} //L�� R�� ���ٸ� ��ȯ(SWAP)�� �ʿ� ���� �� ĭ�� ���ุ ���ָ� ��.
		    L++; R--; //�׸��� L,R �� ĭ �� ����.
	
			/*for (int i = 0; i < 10; i++) { //������ Ȯ�� �κ�.
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
