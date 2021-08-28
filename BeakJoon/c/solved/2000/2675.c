#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main ()
{
	int input = 1, R = 0, output_size = 0, prev_size = 0;
	int i, j, k;
	char S[20], *output;
	scanf("%d", &input);
	output = (char *)malloc(1);
	
	for(i = 0; i < input; i++){
		scanf("%d %s", &R, S);
		prev_size = output_size;
		output_size += strlen(S) * R + 1; //one for '\n' == 13 carige return.
		output = realloc(output, sizeof(char) * output_size);
		for(j = 0; j < strlen(S); j++){
			for(int k = 0; k < R; k++){
				*(output + prev_size + j * R + k) = S[j];
			}
		}
		*(output + output_size - 1) = '\n';
	}
	*(output + output_size) = 0;
	printf("%s", output);
	free(output);
	return 0;
}
