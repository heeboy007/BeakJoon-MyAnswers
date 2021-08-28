#include<stdio.h>
#include<time.h>

int main(){
    char buff[20];
    time_t now = time(NULL);
    strftime(buff, 20, "%Y\n%m\n%d", localtime(&now));
    printf("%s", buff);
    return 0;
}