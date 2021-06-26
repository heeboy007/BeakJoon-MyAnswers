#include<stdio.h>

typedef struct CAKE{
    int x;
    int y;
    int z;
} Cake;

int main(){
    Cake a, b;
    scanf("%d %d %d", &a.x, &a.y, &a.z);
    scanf("%d %d %d", &b.x, &b.y, &b.z);
    printf("%d %d %d", b.x - a.z, b.y / a.y, b.z - a.x);
    return 0;
}