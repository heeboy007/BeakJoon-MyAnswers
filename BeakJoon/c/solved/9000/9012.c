#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

bool isValid(char str[]){
	int height = 0;
	int check = 0;
	char copy[50];
	memset(copy, 0, sizeof(copy));

	//printf("Curr[%d] : %s\n", strlen(str), str);

	if(str[0] != '(' || (strlen(str) % 2))
		return false;

	for(int i = 0; i < strlen(str); i++){
        //if current char is '(' increase height, if is ')' decrease height.
		height = str[i] == '(' ? height + 1 : height - 1;

		if(height == 0){
            if(strlen(str) - 1 == i){ //no more strings to check!
                return true;
            }
            else{ //some strings left to be checked!
                for(int j = i + 1; j < strlen(str); j++){
                    copy[j - i - 1] = str[j];
                }
                if(isValid(copy))
                    return true;
                else
                    return false;
            }
        }
	}
    if(height)
        return false;
    else
        return true;
}

int main ()
{
	int n = 0;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		char input[50];
		scanf("%s", input);
		
		if(isValid(input))
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
