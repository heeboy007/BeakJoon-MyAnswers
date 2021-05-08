#include<stdio.h>

int main ()
{
	int a = 0, b = 0, i = 1;
	char ch;
	
	
    do
	{
	  	ch = getchar();
	  	if(i == 1){
	  			a = ch - 48;
		  }
	  	else if(i == 3){
	  		b = ch - 48;
		  }	
	  	else if(i == 4){
	  		printf("%d\n", a + b);
	  		i = 0;
		}
    	if(ch == '0' || ch == EOF){
			//printf("break");     // EOF is ctrl+z in windows 
    		break;
    	}
    	i += 1;
	}
	while(1);
   
   
	return 0;
}
