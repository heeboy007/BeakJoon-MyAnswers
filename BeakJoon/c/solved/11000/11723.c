#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int main(){

    bool set[20];
    char command[10];
    int input, n;

    memset(set, 0, sizeof(set));
    scanf("%d", &n);
    while(n--){
        scanf("%s", command);
        switch (command[0])
        {
        case 'e': //empty
            for(int i = 0; i < 20; i++){
                set[i] = false;
            }
            break;
        case 'a':
            if(command[1] == 'l'){ // all
                for(int i = 0; i < 20; i++){
                    set[i] = true;
                }
            } else { // add
                scanf("%d", &input);
                set[input - 1] = true;
            }
            break;
        case 't':
            scanf("%d", &input);
            set[input - 1] = !set[input - 1];
            break;
        case 'r':
            scanf("%d", &input);
            set[input - 1] = false;
            break;
        case 'c':
            scanf("%d", &input);
            if(set[input - 1]){
                printf("1\n");
            } else {
                printf("0\n");
            }
            break;
        }
    }

    return 0;
}