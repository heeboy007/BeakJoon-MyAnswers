#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define SWAP(x, y, temp) (temp) = (x), (x) = (y), (y) = (temp)

/*
void print_arr(int* arr){
	do{
		printf("%d,", *arr);
	}
	while(*arr++);
	printf("\n");
}
*/

//random pivot point quicksort
void quicksort(int* arr, int left, int right){
	if(left >= right)
		return;

	int temp;
	int pivot = left + rand() % (right - left + 1);
	int pivot_value = *(arr + pivot);
	int low = (left == pivot) ? left + 1 : left;
	int high = (right == pivot) ? right - 1 : right;

	while(low < high){

		//low can have : right + 1
		while(low < right && *(arr + low) <= pivot_value){
			if(++low == pivot){
				if(pivot == right)
					break;
				else 
					low++;
			}
		}
		//high can have : low - 1
		while(high > left && *(arr + high) >= pivot_value){
			if(--high == pivot){
				if(pivot == left)
					break;
				else
					high--;
			}
		}

		if(low < high){
			SWAP(*(arr + low), *(arr + high), temp);
		}
	}
	
	if(high > pivot){
		SWAP(*(arr + pivot), *(arr + high), temp);
		pivot = high;
	} else if(low < pivot) {
		SWAP(*(arr + pivot), *(arr + low), temp);
		pivot = low;
	}

	quicksort(arr, left, pivot - 1);
	quicksort(arr, pivot + 1, right);
}

int main(){
	int count = 0;
	int* numbers;

	scanf("%d", &count);
	numbers = (int *)malloc(sizeof(int) * (count + 1));
	memset(numbers, 0, sizeof(int) * (count + 1));

	for(int i = 0; i < count; i++){
		scanf("%d", numbers + i);
	}

	quicksort(numbers, 0, count - 1);

	setvbuf(stdout, NULL, _IOFBF, 4096);
	for(int i = 0; i < count; i++){
		printf("%d\n", *(numbers + i));
	}
	fflush(stdout);

	free(numbers);
}