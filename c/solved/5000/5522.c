#include<stdio.h>

int main(){
    int sum = 0;
    
    for(int i = 0; i < 5; i++){
        int input;
        scanf("%d", &input);
        sum += input;
    }
    printf("%d", sum);

    return 0;
}