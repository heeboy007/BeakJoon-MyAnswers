#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LENGTH 2048

typedef struct NUM {
	bool is_minus;
	char *num;
} Bignumber;

void add(Bignumber n1, Bignumber n2, Bignumber nr);
void subtract(Bignumber n1, Bignumber n2, Bignumber nr);

int mul_two_char(char c1, int mul){
	return (int)(c1 - 48) * mul;
}

void multiply_single(Bignumber n1, int mul, int digit, Bignumber nr){
	memset(nr.num, 0, MAX_LENGTH * sizeof(char));
	int prev = 0;
	char *c1 = n1.num, *res = nr.num;
	for(int i = 0; i < digit; i++){
		*res = '0';
		res++;
	}
	while(*c1 || prev){
		char a = (*c1 ? *c1 : '0'); //needed if it has prev
		int result = mul_two_char(a, mul) + prev;
		*res = (char)(result % 10 + 48);
		prev = result / 10;
		c1++; res++;
	}
}

void multiply(Bignumber n1, Bignumber n2, Bignumber nr){
	memset(nr.num, 0, MAX_LENGTH * sizeof(char));
	if(!strcmp(n1.num, "0") || !strcmp(n2.num, "0")){
		*nr.num = '0';
		return;
	}

	int index = 0;
	bool plus = n1.is_minus == n2.is_minus;
	char *c2 = n2.num;
	Bignumber temp;
	temp.num = (char*)malloc(MAX_LENGTH * sizeof(char));
	memset(temp.num, 0, MAX_LENGTH * sizeof(char));
	temp.is_minus = false;
	nr.is_minus = false;

	while(*c2){
		int mul = (*c2 - 48);
		if(mul){ //skip 0, no need.
			multiply_single(n1, mul, index, temp);
			add(temp, nr, nr);
		}
		c2++; index++;
	}
	if(!plus){
		*(nr.num + strlen(nr.num)) = '-';
	}

	free(temp.num);
}

bool front_is_bigger(char *c1, char *c2){
	int result1 = strlen(c1);
	int result2 = strlen(c2);
	if(result1 == result2){
		c1 += result1 - 1;
		c2 += result1 - 1;
		while(*c1 == *c2 && result2 > 0){
			result2--;
			c1--;
			c2--;
		}
		return *c1 > *c2;
	} else {
		return result1 > result2;
	}
	return false;
}

int add_two_char(char a, char b){
	return (int)(a + b - 96);
}

void add(Bignumber n1, Bignumber n2, Bignumber nr){
	if(n1.is_minus == n2.is_minus){
		if(n2.num != nr.num)
			memset(nr.num, 0, MAX_LENGTH * sizeof(char));
		int prev = 0;
		char *c1 = n1.num, *c2 = n2.num, *res = nr.num;
		while(*c1 || *c2 || prev){
			char a = (*c1 ? *c1 : '0'), b = (*c2 ? *c2 : '0');
			
			int result = add_two_char(a, b) + prev;
			*res = (char)(result % 10 + 48);
			prev = result / 10;
			c1++; c2++; res++;
		}
		if(n1.is_minus)
			*res = '-';
	} else {
		if(front_is_bigger(n1.num, n2.num)){
			n2.is_minus = !n2.is_minus;
			subtract(n1, n2, nr);
		} else {
			n1.is_minus = !n1.is_minus;
			subtract(n2, n1, nr);
		}
	}
}

int sub_two_char(char a, char b){
	return (int)(a - b);
}

void subtract(Bignumber n1, Bignumber n2, Bignumber nr){
	if(n1.is_minus == n2.is_minus){
		memset(nr.num, 0, MAX_LENGTH * sizeof(char));
		char *c1 = n1.num, *c2 = n2.num, *res = nr.num;
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
		if(n1.is_minus)
			*res = '-';
	} else {
		n2.is_minus = !n2.is_minus;
		add(n1, n2, nr);
	}
}

bool reverse(Bignumber n1){
	char* start = n1.num;
	bool result = *start == '-';
	while(*(n1.num)) n1.num++;
	n1.num--;
	while(start < n1.num){
		char ch = *start;
		*start = *(n1.num);
		*(n1.num) = ch;
		start++;
		n1.num--;
 	}
	return result;
}

void print_Bignum(Bignumber n1){
	printf("%s", n1.is_minus ? "-" : "");
	printf("%s\n", n1.num);
}

int main(){
	Bignumber n1, n2, nr;

	n1.num = (char *)malloc(MAX_LENGTH * sizeof(char));
	n2.num = (char *)malloc(MAX_LENGTH * sizeof(char));
	nr.num = (char *)malloc(MAX_LENGTH * sizeof(char));
	memset(n1.num, 0, MAX_LENGTH * sizeof(char));
	memset(n2.num, 0, MAX_LENGTH * sizeof(char));

	scanf("%s", n1.num);
	scanf("%s", n2.num);
	n1.is_minus = reverse(n1);
	n2.is_minus = reverse(n2);
	if(*(n1.num + strlen(n1.num) - 1) == '-')
		*(n1.num + strlen(n1.num) - 1) = '\0';
	if(*(n2.num + strlen(n2.num) - 1) == '-')
		*(n2.num + strlen(n2.num) - 1) = '\0';
	
	add(n1, n2, nr);
	reverse(nr);
	print_Bignum(nr);

	if(front_is_bigger(n1.num, n2.num)){
		subtract(n1, n2, nr);
	} else {
		n1.is_minus = !n1.is_minus; n2.is_minus = !n2.is_minus;
		subtract(n2, n1, nr);
		n1.is_minus = !n1.is_minus; n2.is_minus = !n2.is_minus;
	}
	reverse(nr);
	print_Bignum(nr);

	multiply(n1, n2, nr);
	reverse(nr);
	print_Bignum(nr);

	free(n1.num);
	free(n2.num);
	free(nr.num);

	return 0;
}