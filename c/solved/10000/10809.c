#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
	
	int i = 0;
	char str[100], cord[26];
	memset(cord, 0, sizeof(cord));
	
	scanf("%s", str);
	
	while(str[i]){
		//printf("%d : %c\n", str[i], str[i]);
		if('a' <= str[i] && str[i] <= 'z'){
			if(!cord[str[i] - 97])
				cord[str[i] - 97] = i + 1;
		}
		i++;
	} //until is not nullchar
		
	for(i = 0; i < 26; i++)
		printf("%d ", cord[i] - 1); 
	
	return 0;
}

