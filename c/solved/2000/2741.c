#include<stdio.h>
#include<math.h>
#include<stdlib.h>

char* my_strcmp(char* dest, const char *source){
	int i = 0;
	while(source[i] != 0){
		dest[i] = source[i];
		i++;
	}
	return dest + i;
}

int main(){
	
	int n = 0, len = 0;
	char *output, *next;
	char curr_num[7];
	scanf("%d", &n);
	
	for(int i = 10; i <= n; i++){
		len += (int)log10(i);
	}
	len += n * 2 + 1;
	
	output = (char*)malloc(len);
	next = output;
	
	for(int i = n; i >= 1; i--){
		sprintf(curr_num, "%d\n", i);
		next = my_strcmp(next, curr_num);
	}
	*next = '\0';
	printf("%s", output);
	free(output);
	
	return 0;
}

