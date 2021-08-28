#include<stdio.h>

int main(){
    char a[10] = "가\0";
    scanf("%s", a);
    printf("%s", a);
    printf("%d", a[0] * 0XFF + a[1] - 0XAC00);
    return 0;
}