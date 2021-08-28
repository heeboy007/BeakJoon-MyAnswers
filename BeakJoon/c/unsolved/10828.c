#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _LinkedList
{
    int value;
    struct _LinkedList* next;
} LinkedList;

void freeList(LinkedList* node){
    while(node){
        LinkedList* prev = node;
        node = node->next;
        free(prev);
    }
}

int main(){
    int input, size = 0;
    LinkedList* node = NULL;

    scanf("%d", &input);
    for(int i = 0; i < input; i++){
        int key = 0;
        char command[6];
        scanf("%s", command);
        switch (command[0])
        {
        case 'e': //empty
            if(node)
                printf("1\n");
            else
                printf("0\n");
            break;
        case 'p':
            if(command[1] = 'o'){ //pop
                LinkedList* prev = node;
                node = node->next;
                printf("%d\n", prev->value);
                free(prev);
                size--;
            }
            else{ //push
                LinkedList* new_node = (LinkedList*)malloc(sizeof(LinkedList));
                scanf("%d", &new_node->value);
                new_node->next = node;
                node = new_node;
                size++;
            }
            break;
        case 's': //size
            printf("%d\n", size);
            break;
        case 't': //top
            if(node)
                printf("%d\n", node->value);
            else
                printf("-1\n");
        default:
            printf("No, It can't be... It can't be...");
            break;
        }
    }

    freeList(node);

    return 0;
}