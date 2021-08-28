#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DIGIT 1024 //just in case it overflows a bit when calculating very big numbers...

int compare(char *c1, char *c2){
	
	int zero = 0;
	while(c1[zero] == '0')
		zero += 1;
	c1 = c1 + zero;
	
	zero = 0;
	while(c2[zero] == '0')
		zero += 1;
	c2 = c2 + zero;
	
	int digit_c1 = strlen(c1), digit_c2 = strlen(c2);
	
	if(digit_c1 > digit_c2){ //c1 is bigger 
		return -1;
	}
	else if(digit_c1 < digit_c2){ //c2 is bigger 
		return 1;
	}
	else {
		for(int i = 0; i < digit_c1; i++){
			if(c1[i] > c2[i]){ //c1 is bigger
				return -1; 
			}
			else if(c1[i] < c2[i]){ //c2 is bigger
				return 1;
			}
		}
		return 0; //gone through the entire loop means c1 = c2
	}
}

//mul must be 0 ~ 9
char* multiply(char *c, int mul){
	int temp = 0;
	for(int i = strlen(c) - 1; i >= 0; i--){
		temp = (c[i] - 48) * mul + temp;
		c[i] = (temp % 10) + 48;
		temp /= 10;
	}
	if(temp != 0){
		for(int i = strlen(c) - 1; i >= 0; i--){
			c[i + 1] = c [i];
		}
		c[0] = temp + 48;
	}
	return c;
}

char* subtract(char *c1, char *c2){
	int not_enough = 0, sub_num = 0;
	int i = strlen(c2) - 1;
	bool is_number_zero = false;
	for(int j = strlen(c1) - 1; j >= 0; j--){
		sub_num = (i >= 0 ? c2[i] : '0'); //rest of the higher digits will be consider as '0', as it should be.
		//printf("Before / i : %d\tj : %d\tc1[j] : %c\tc2[i] : %c\t n_e : %d\tcon : %d\n", i, j, c1[j], sub_num, not_enough, i >= 0 ? c2[i] : '0');
		if(c1[j] - not_enough >= sub_num){
			c1[j] = (c1[j] - not_enough) - sub_num + 48;
			not_enough = 0;
		}
		else{
			c1[j] = (c1[j] - not_enough) + 10 - sub_num + 48;
			not_enough = 1;
		}
		//printf("After / i : %d\tj : %d\tc1[j] : %c\tc2[i] : %c\t n_e : %d\tcon : %d\n", i, j, c1[j], sub_num, not_enough, i >= 0 ? c2[i] : '0');
		i -= 1;
	}
	/*i = 0;
	while(c1[i] == '0'){
		if(c1[i + 1] == 0) // the hole string is made of '0'
			break;
		i += 1;
	}*/
	return c1; //it has it's own problem but we'll just ignore it for now...
}

char* my_strncpy(char *destination, char *source, int start, int count){
	//printf("copy : %d ~ %d\n", start, start + count);
	for(int i = start; i < start + count; i++){	
		//printf("source : %c\tdestination : %c\n", source[i], destination[i - start]);
		destination[i - start] = source[i]; 
	}
	destination[count] = 0;
	return destination;
}

int main()
{
	char a[MAX_DIGIT] = {0}, b[MAX_DIGIT] = {0}, share[MAX_DIGIT] = {0};
	char cp_a[MAX_DIGIT] = {0}, cp_b[MAX_DIGIT] = {0};
	
	int i = 0, start = 0, result = 0, zero_digits = 0;
	
	scanf("%s", &a);
	scanf("%s", &b);
	
	//find where to start
	while(compare(a, b) <= 0){
		strncpy(cp_a, a, i + 1);
		//printf("copyed : %s\n", cp_a);
		result = compare(cp_a, b);
		if(compare(cp_a, b) <= 0){
			start = i;
			break;
		}
		i += 1;
	}
	
	i = 0;
	//keep multiply and subtracting number's till the end. 
	while(a[i + start] != 0){
		while(a[zero_digits] == '0')
			zero_digits += 1;
		my_strncpy(cp_a, a, zero_digits, start + i + 1 - zero_digits);
		for(int j = 9; j >= 0; j--){
			strcpy(cp_b, b); //reset cp_b
			//printf("cp_a : %s\tb : %s\t", cp_a, b);
			multiply(cp_b, j); //multiply
			//printf("aftermul cp_b : %s\n", cp_b);
			if(compare(cp_a, cp_b) <= 0){ //the moment cp_a is bigger or same than multiplied b
				subtract(cp_a, cp_b);
				share[i] = j + 48; //record the number
				//printf("recorded : %c\n", share[i]);
				for(int k = 0; k < start + i + 1 - zero_digits; k++){
					a[zero_digits + k] = cp_a[k];
				}
				//printf("a : %s\tcp_a : %s\tz_d : %d\n", a, "N/A", zero_digits);
				//zero_digits = (share[i] == '0' && cp_a[0] != '0' ? zero_digits + 1 : 0);
				break;
			}
		}
		i += 1;	
	}
	
	i = 0;
	start = 0;
	while(share[i] == '0')
		i += 1;
		
	while(a[start] == '0'){
		if(a[start + 1] == 0){
			break;
		}
		start += 1;
	}
		
	//printf("Share : %s\nRemainder : %s", share + i, a + start);
	printf("%s\n%s", share + i, a + start);
}
