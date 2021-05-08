#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main ()
{
	char str[6];
	
	do{
		memset(str, 0, 6);
		scanf("%s", str);
	
		if(!strcmp(str,"0"))
			break;
	
		bool is_pel = true;	
		for(int i = 0; i < strlen(str) / 2; i++){
			if(str[i] != str[strlen(str) - 1 - i]){
				is_pel = false;
			}
		}
		
		if(is_pel)
			printf("yes\n");
		else
			printf("no\n");
	} while(true);
	
	return 0;
}
