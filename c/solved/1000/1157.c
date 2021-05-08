#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main ()
{
	char str[1000000], ch;
	int alphabets[26];
	memset(str, 0, 1000000);
	memset(alphabets, 0, sizeof(alphabets));
	
	scanf("%s", str);
	
	for(int i = 0; str[i] != '\0'; i++){
		if('A' <= str[i] && str[i] <= 'Z'){ //capital
			alphabets[str[i] - 65] += 1;
		} 
		else if('a' <= str[i] && str[i] <= 'z') { //little 
			alphabets[str[i] - 97] += 1;
		}
	}
	
	int max = -1;
	//bool stalemate = false;
	for(int i = 0; i < 26; i++){
		if(alphabets[i] > max){
			max = alphabets[i];
			ch = i + 65;
		} else if (alphabets[i] == max){
			ch = '?';
		}
	}
	
	printf("%c\n", ch);
	
	return 0;
}
