#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LENGTH 256

typedef struct NUM {
	bool is_reversed;
	char *num;
} Bignumber;

void reverse(Bignumber n1){
    n1.is_reversed = !n1.is_reversed;
	char* start = n1.num;
	while(*(n1.num)) n1.num++;
	n1.num--;
	while(start < n1.num){
		char ch = *start;
		*start = *(n1.num);
		*(n1.num) = ch;
		start++;
		n1.num--;
 	}
}

void multiply_single(Bignumber n1, Bignumber nr){
    if(!n1.is_reversed)
        reverse(n1);
	int prev = 0;
	char *c1 = n1.num, *res = nr.num;
	while(*c1 || prev){
		char a = (*c1 ? *c1 : '0'); //needed if it has prev
		int result = (int)(a - 48) * 2 + prev;
		*res = (char)(result % 10 + 48);
		prev = result / 10;
		c1++; res++;
	}
}

void add(Bignumber n1, Bignumber n2, Bignumber nr){
    if(!n1.is_reversed)
        reverse(n1);
    if(!n2.is_reversed)
        reverse(n2);
	int prev = 0;
	char *c1 = n1.num, *c2 = n2.num, *res = nr.num;
	while(*c1 || *c2 || prev){
		char a = (*c1 ? *c1 : '0'), b = (*c2 ? *c2 : '0');
		
		int result = (int)(a + b - 96) + prev;
		*res = (char)(result % 10 + 48);
		prev = result / 10;
		c1++; c2++; res++;
	}
}

void print_Bignum(Bignumber n1){
    reverse(n1);
	printf("%s\n", n1.num);
    reverse(n1);
}

int main(){
	Bignumber dp[251];
    Bignumber temp;
    int max = 3, n = 0;
    char temp_num[MAX_LENGTH];
    temp.num = temp_num;
    temp.is_reversed = true;

    for(int i = 0; i < 3; i++){
        dp[i].num = (char *)malloc(MAX_LENGTH * sizeof(char));
        memset(dp[i].num, 0, MAX_LENGTH * sizeof(char));
        dp[i].is_reversed = true;
    }
    dp[0].num[0] = '1';
    dp[1].num[0] = '1';
    dp[2].num[0] = '3';

    while(scanf("%d", &n) != EOF){
        for(int i = max; i <= n; i++){
            dp[i].num = (char *)malloc(MAX_LENGTH * sizeof(char));
            dp[i].is_reversed = true;
            memset(dp[i].num, 0, MAX_LENGTH * sizeof(char));
            memset(temp_num, 0, MAX_LENGTH * sizeof(char));

            multiply_single(dp[i - 2], temp);
            add(dp[i - 1], temp, dp[i]);
        }
        max = n + 1 > max ? n + 1 : max;
        
        print_Bignum(dp[n]);
    }

    for(int i = 0; i < max; i++){
        free(dp[i].num);
    }

	return 0;
}