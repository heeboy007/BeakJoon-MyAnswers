#include<stdio.h>
#include<unistd.h>

int main(){
	
	/*int count = 0;
	char ch, prev = ' ';
	while((ch = getchar()) != '\n'){
		if(prev == ' ' && ch != ' ')
			count++;
		prev = ch;
		//printf("%c : %d\n", ch != ' ' ? ch : '=', ch );
	}*/
	
	//for anyone out there this is not my code! credits for da3107
	
	int i = 0, count = 0;
	char str[1000005];
	
	read(0, str, 1000005); //force read bytes it will end by null char '0'
	
	if(str[i] == ' ') //ignore first blank
		i = 1;
	if(str[i] && str[i] != '\n') //if str is not blank!
		count = 1;
		
	while(str[i]){
		if((str[i] == ' ') && (str[i + 1] != '\n') && (str[i + 1] != 0)) //count all blank except for the last one.
			count++;
		i++;
	} //until is not nullchar
		
	printf("%d", count); 
	return 0;
}
