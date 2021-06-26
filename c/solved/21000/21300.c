#include<stdio.h>

int main(){
    int sum = 0;
    for(int i = 0; i < 6; i++){
        int input;
        scanf("%d", &input);
        sum += input;
    }
    printf("%d", sum * 5);
    return 0;
}