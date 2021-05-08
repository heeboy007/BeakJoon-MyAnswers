#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Persons{
    int age;
    int index;
    char name[101];
} Person;

int Compare(Person a, Person b){
	int len_a = strlen(a.name), len_b = strlen(b.name);
    if(b.age > a.age){
        return 1;
    }
    else if(a.age > b.age){
        return -1;
    }
	if(b.index > a.index){
		return 1;
	}
	else if(a.index > b.index){
		return -1;
	}
    else{ //there is a reason this section exists. What if you have only 1 record?
        return 0;
    }
}


void QuickSort(Person arr[], int left, int right) {
	int L = left, R = right;
	Person temp;
	Person pivot = arr[(left + right) / 2]; //피봇 위치(중앙)의 값을 받음.

  //아래의 while문을 통하여 pivot 기준으로 좌, 우 크고 작은 값 나열. = Partition
	while (L <= R) {
		//pivot이 중간 값이고, 비교 대상 arr[L], arr[R]은 pivot과 비교하니 중간 지점을 넘어가면 종료로 볼 수 있음.
	    while (Compare(arr[L], pivot) > 0) //left부터 증가하며 pivot 이상의 값을 찾음.
			L++;
	    while (Compare(arr[R], pivot) < 0) //right부터 감소하며 pivot 이하 값을 찾음.
			R--;
	    //L, R 모두 최대 pivot 위치까지 이동.
	
	    if (L <= R) { //현재 L이 R이하면. (이유 : L>R 부분은 이미 정리가 된 상태임).
	    	if (L != R) { //같지 않은 경우만.
	        	temp = arr[L];
	        	arr[L] = arr[R];
	    		arr[R] = temp;
	    	} //L과 R이 같다면 교환(SWAP)은 필요 없고 한 칸씩 진행만 해주면 됨.
		    L++; R--; //그리고 L,R 한 칸 더 진행.
	
			/*for (int i = 0; i < 3; i++) { //데이터 확인 부분.
	    		printf("%d %s\n", arr[i].age, arr[i].name);
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

int main(){
	int n = 0;
	scanf("%d", &n);
	
    Person* arr = malloc(sizeof(Person) * n);
	
	//essential init
	for(int i = 0; i < n; i++){
        memset(arr[i].name, 0, 100);
        arr[i].index = i;
		scanf("%d %s", &arr[i].age, &arr[i].name);
	}

    //QuickSort everything!
    QuickSort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++){
		printf("%d %s\n", arr[i].age, arr[i].name);
        //printf("[%d] : %d/%d/%s\n", i, arr[i].age, arr[i].index, arr[i].name);
	}
	
    free(arr);
	return 0;
}