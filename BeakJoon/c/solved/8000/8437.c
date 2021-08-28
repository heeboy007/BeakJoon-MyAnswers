#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAX_LENGTH 256

void divide_by_two(char *c1, char *res){
	memset(res, 0, MAX_LENGTH * sizeof(char));
	while(*c1){
		int result = (*(c1 + 1) % 2) * 5 + (*c1 - 48) / 2;
		if(*(c1 + 1) || result)
			*res = (char)(result + 48);
		c1++; res++;
	}
}

int add_two_char(char a, char b){
	return (int)(a + b - 96);
}

void add(char *c1, char *c2, char *res){
	memset(res, 0, MAX_LENGTH * sizeof(char));
	int prev = 0;
	while(*c1 || *c2 || prev){
		char a = (*c1 ? *c1 : '0'), b = (*c2 ? *c2 : '0');
		
		int result = add_two_char(a, b) + prev;
		*res = (char)(result % 10 + 48);
		prev = result / 10;
		c1++; c2++; res++;
	}
}

int sub_two_char(char a, char b){
	return (int)(a - b);
}

void subtract(char *c1, char *c2, char *res){
	memset(res, 0, MAX_LENGTH * sizeof(char));
	if(!strcmp(c1, c2)){
		*res = '0';
		return;
	}

	int prev = 0;
	while(*c1 || *c2 || prev){
		char a = (*c1 ? *c1 : '0'), b = (*c2 ? *c2 : '0');
		
		int result = sub_two_char(a, b) + prev;
		*res = (char)((result + 10) % 10 + 48);
		prev = result < 0 ? -1 : 0;
		c1++; c2++; res++;
	}
	while(*(res - 1) == '0'){
		res--;
		*res = '\0';
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
    char *c1, *c2, *res1, *res2;

    c1 = (char *)malloc(MAX_LENGTH * sizeof(char));
	c2 = (char *)malloc(MAX_LENGTH * sizeof(char));
	res1 = (char *)malloc(MAX_LENGTH * sizeof(char));
    res2 = (char *)malloc(MAX_LENGTH * sizeof(char));

	memset(c1, 0, MAX_LENGTH * sizeof(char));
	memset(c2, 0, MAX_LENGTH * sizeof(char));

	scanf("%s", c1);
	scanf("%s", c2);
	reverse(c1);
	reverse(c2);

    add(c1, c2, res1);
    divide_by_two(res1, res2);
	reverse(res2);
	printf("%s\n", res2);

    subtract(c1, c2, res1);
	divide_by_two(res1, res2);
	reverse(res2);
	printf("%s\n", res2);

	free(c1);
	free(c2);
	free(res1);
    free(res2);

	return 0;
}