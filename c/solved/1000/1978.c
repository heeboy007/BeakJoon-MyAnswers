#include<stdio.h>

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};

//OK : CHECKED
//more than 3~-> incoming numbers are all odd numbers
int is_prime(int test_subject){
	if(test_subject == 1)
		return 0;
	//check if is dividable with all primes less than 43, if it's not, it's prime. 
	for(int i = 0; primes[i] * primes[i] < 1000; i++){
		if(!(test_subject % primes[i])){ //this number is dividable with this prime probably not prime.
			if(test_subject != primes[i]){ //this number itself is not prime? complete non-prime number.
				return 0;
			} else { //oh actually this is the prime itself.
				return 1;
			}
		}
	}
	return 1;
}

int main(){
	int n = 0, count = 0;
	scanf("%d", &n);
	
	//essential init
	for(int i = 0; i < n; i++){
		int input = 0;
		scanf("%d", &input);
		
		//printf("%d : %d\n", input, is_prime(input));
		count += is_prime(input);
	}
	
	printf("%d", count);
	
	return 0;
}
