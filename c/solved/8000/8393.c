#include<stdio.h>

int main(){
    long sum = 0;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        sum += i;
    }
    printf("%ld", sum);

    return 0;
}