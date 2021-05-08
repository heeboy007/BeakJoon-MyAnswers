#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Cards
{
    int key;
    int value;
    struct Cards* next;
} Card;

int N = 0;

unsigned int hashCode(unsigned int x){
    x = x ^ 401;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    //printf("x : %d\n", x);
    return x;
}

int get(Card** arr, int key){
    int index = hashCode(key) % N;
    if(arr[index]){ //indexed hash table is not empty.
        Card* node = arr[index];
        do{
            if(node->key == key){
                return node->value;
            }
        } while (node = node->next);
    }
    return 0;
}

void increase(Card** arr, int key){
    int index = hashCode(key) % N;
    if(arr[index]){ //hash table is not empty.
        Card* node = arr[index];
        while(node->next){
            if(node->key == key){
                node->value++;
                return;
            }
            node = node->next;
        }
        if(node->key == key){
            node->value++;
            return;
        }

        //if there is no existing node, make new one.
        Card* new_card = (Card*)malloc(sizeof(Card));
        new_card->key = key;
        new_card->value = 1;
        new_card->next = NULL;
        node->next = new_card;
    } else {  //indexed hash table is empty.
        Card* new_card = (Card*)malloc(sizeof(Card));
        new_card->key = key;
        new_card->value = 1;
        new_card->next = NULL;
        arr[index] = new_card;
    }
}

void freeHash(Card** arr){
    for(int i = 0; i < N; i++){
        if(!arr[i])
            continue;
        Card* node = arr[i];
        while(node->next){
            Card* prev = node;
            node = node->next;
            free(prev);
        }
        free(node);
    }
    free(arr);
}

int main(){

    scanf("%d", &N);
    Card **arr = (Card**)malloc(sizeof(Card*) * N);
    memset(arr, 0, sizeof(Card*) * N);

    for(int i = 0; i < N; i++){
        int key = 0;
        scanf("%d", &key);
        increase(arr, key);
    }

    int input = 0;
    scanf("%d", &input);
    for(int i = 0; i < input; i++){
        int key = 0;
        scanf("%d", &key);
        printf("%d ", get(arr, key));
    }

    freeHash(arr);

    return 0;
}