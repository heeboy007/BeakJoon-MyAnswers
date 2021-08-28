#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void QuickSort(long arr[], int left, int right) {
	int L = left, R = right;
	int temp;
	int pivot = arr[(left + right) / 2]; //�Ǻ� ��ġ(�߾�)�� ���� ����.
	
	//�Ʒ��� while���� ���Ͽ� pivot �������� ��, �� ũ�� ���� �� ����. = Partition
	while (L <= R) {
		//pivot�� �߰� ���̰�, �� ��� arr[L], arr[R]�� pivot�� ���ϴ� �߰� ������ �Ѿ�� ����� �� �� ����.
	    while (arr[L] < pivot) //left���� �����ϸ� pivot �̻��� ���� ã��.
			L++;
	    while (arr[R] > pivot) //right���� �����ϸ� pivot ���� ���� ã��.
			R--;
	    //L, R ��� �ִ� pivot ��ġ���� �̵�.
	
	    if (L <= R) { //���� L�� R���ϸ�. (���� : L>R �κ��� �̹� ������ �� ������).
	    	if (L != R) { //���� ���� ��츸.
	        	temp = arr[L];
	        	arr[L] = arr[R];
	    		arr[R] = temp;
	    	} //L�� R�� ���ٸ� ��ȯ(SWAP)�� �ʿ� ���� �� ĭ�� ���ุ ���ָ� ��.
		    L++; R--; //�׸��� L,R �� ĭ �� ����.
	
			/*for (int i = 0; i < 5; i++) { //������ Ȯ�� �κ�.
	    		printf("%d ", arr[i]);
	    	}
	    	printf("\n");*/
		}
	}

	if (left < R)
		QuickSort(arr, left, R);
	if (L < right)
    	QuickSort(arr, L, right);
}

bool find(long arr[], int n, long search){
	int left = 0, right = n, mid = n / 2;
	long pivot = arr[mid];
	
	if(search == arr[0])
		return true;
	
	do {
		if(pivot < search) { //more than current half
			left = mid;
		} else if (pivot == search) {
			return true;
		} else { //pivot > search
			right = mid;
		}
		mid = (left + right) / 2;
		//printf("%d : %d : %d\n", left, mid, right);
		pivot = arr[mid];
	} while (left != mid);
	
	return false;
}

int main ()
{
	int n, m;
	scanf("%d", &n);
	
	long *numbers = malloc(sizeof(long) * n);
	
	for(int i = 0; i < n; i++){
		scanf("%ld", &(numbers[i]));
	}
	
	QuickSort(numbers, 0, n - 1);
	
	scanf("%d", &m);
	
	long *searches = malloc(sizeof(long) * m);
	
	for(int i = 0; i < m; i++){
		scanf("%ld", &searches[i]);
		searches[i] = find(numbers, n, searches[i]) ? 1 : 0;
	}
	
	for(int i = 0; i < m; i++){
		printf("%ld\n", searches[i]);
	}
	
	free(numbers);
	free(searches);
	return 0;
}
