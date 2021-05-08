#include<stdio.h>

int main(){
	int a = 0, b = 0, c = 0;
	
	while(1){
		scanf("%d %d %d", &a, &b, &c);
		
		if(a == 0 && b == 0 && c == 0)
			break;
			
		if(b > a && b > c){
			int temp = b;
			b = c;
			c = temp;
		} else if (a > b && a > c) {
			int temp = a;
			a = c;
			c = temp;
		}
			
		if(a*a + b*b == c*c)
			printf("right\n");
		else
			printf("wrong\n");
	}
	
	return 0;
}
