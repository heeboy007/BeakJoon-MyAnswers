#include<stdio.h>

int solution(int number) {
    number--;
	int mul_3 = (number / 3), mul_5 = (number / 5), mul_15 = (number / 15);
    int sum = 0;
    
    printf("%d\n", 3 * mul_3 * (mul_3 + 1) / 2);
    sum += 3 * mul_3 * (mul_3 + 1) / 2;
    printf("%d\n", 5 * mul_5 * (mul_5 + 1) / 2);
    sum += 5 * mul_5 * (mul_5 + 1) / 2;
    printf("%d\n", 15 * mul_15 * (mul_15 + 1) / 2);
    sum -= 15 * mul_15 * (mul_15 + 1) / 2;
    
    number++;
    return (number < 0 ? 0 : sum);
}

int main(){
    printf("%d\n", solution(10));

    return 0;
}