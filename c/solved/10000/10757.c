#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAX_LENGTH 16384

int add_two_char(char a, char b){
	return (int)(a + b - 96);
}

void add(char *c1, char *c2, char *res){
	int prev = 0;
	while(*c1 || *c2 || prev){
		char a = (*c1 ? *c1 : '0'), b = (*c2 ? *c2 : '0');
		
		int result = add_two_char(a, b) + prev;
		*res = (char)(result % 10 + 48);
		prev = result / 10;
		c1++; c2++; res++;
	}
}

void reverse(char *c1){
	char* start = c1;
	while(*c1) c1++;
	c1--;
	while(start < c1){
		char ch = *start;
		*start = *c1;
		*c1 = ch;
		start++;
		c1--;
 	}
}

int main(){

    char *c1, *c2, *res;

	c1 = (char *)malloc(MAX_LENGTH * sizeof(char));
	c2 = (char *)malloc(MAX_LENGTH * sizeof(char));
	res = (char *)malloc(MAX_LENGTH * sizeof(char));
	memset(c1, 0, MAX_LENGTH * sizeof(char));
	memset(c2, 0, MAX_LENGTH * sizeof(char));
    memset(res, 0, MAX_LENGTH * sizeof(char));

	scanf("%s", c1);
	scanf("%s", c2);
	reverse(c1);
	reverse(c2);
	
	add(c1, c2, res);
	reverse(res);
	printf("%s", res);

	free(c1);
	free(c2);
	free(res);

	return 0;
}