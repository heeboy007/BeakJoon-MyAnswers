#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedLists{
	int content;
	void *next;
} Node;


int main(){
	
	int n = 0;
	Node *first, *last;
	scanf("%d", &n);
	
	first = (Node *)malloc(sizeof(Node));
	first->content = 1;
	last = first;
	
	for(int i = 2; i <= n; i++){
		Node *node = (Node *)malloc(sizeof(Node));
		node->content = i;
		last->next = node;
		last = node;
	}
	
	last->next = NULL;
	
	/*Node *node = first;
	printf("%d\n", node->content);
	while (node->next != NULL) {
		node = node->next;
		printf("%d\n", node->content);	
	} */
	
	
	while(n > 1){
		Node *temp = first; 
		first = first->next; //find next node
		free(temp); //destroy
		
		if(first->next == NULL)
			break;
		
		temp = first->next; //temp will be the next first node
		first->next = NULL; //unlink connection with next node
		last->next = first; //send first node to the last
		last = last->next; //now update last node
		last->next = NULL; //just in case...
		first = temp; //now update first node
		
		/*Node *node = first;
		printf("start\n%d\n", node->content);
		while (node->next != NULL) {
			node = node->next;
			printf("%d\n", node->content);	
		} 
		printf("end\n");*/
		
		n--;
	}
	
	printf("%d", first->content);
	return 0;
}
