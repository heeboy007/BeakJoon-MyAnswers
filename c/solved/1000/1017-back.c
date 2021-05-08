#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX 26
#define DEFAULT_VALUE -1

int primes[14] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47};
bool is_first_even = false;
int N = 0;
int evens[MAX], odds[MAX];// = {0};
int answer[MAX];// = {0};

int route[MAX][MAX];// = {{DEFAULT_VALUE}};
int match[MAX];// = {DEFAULT_VALUE};
bool is_matched[MAX];// = {false};

bool dfs(int try_this){
	if(try_this == DEFAULT_VALUE)
		return false;
	//try every avaliable connection for this node.
	for(int i = 0; route[try_this][i] != DEFAULT_VALUE; i++){
		//try to take a match here!
		int attempt = route[try_this][i];
		
		//that node is already taken!
		if(is_matched[attempt])
			continue;
				
		//oh this node seems to be empty!
		is_matched[attempt] = true;
		
		//if one of two :
		//nobody has taken it, let's yoink it fast! 
		//somebody had taken it, let's ask them if they have another choice.
		if(match[attempt] == DEFAULT_VALUE || dfs(match[attempt])){
			match[attempt] = try_this; // match complete!
			return true;
		}
	}	
	return false;
}

//input must be the index number of the desired node.
//find if there is a valid match for forced connections.
bool is_there_vaild_match(int force_route){
	match[force_route] = 0; //force match to first node. not default!
	is_matched[force_route] = true;
	
	for(int i = 1; i < N/2; i++){
		for(int j = 0; j < MAX; j++)
			if(j != force_route)
				is_matched[j] = false;
		if(!dfs(i)) //couldn't find vaild match.
			return false;
	}
	return true; //there is a way to pair.
}

void add_answer(int item){
	static int answer_count = 0;
	for(int i = 0; i < answer_count; i++){
		if(item < answer[i]){
			int temp = answer[i];
			answer[i] = item;
			item = temp;
		}
	}
	answer[answer_count] = item;
	answer_count += 1;
}

void print_answer(){
	if(answer[0] == 0){
		printf("-1\n");
		return;
	}
	
	for(int i = 0; answer[i] != 0; i++){
		printf("%d\n", answer[i]);
	}
}

void extract_answer(){
	for(int i = 0; i < N/2; i++){
		if(route[i][0] == DEFAULT_VALUE){
			printf("-1\n");
			return;
		}
	}
	
	for(int i = 0; route[0][i] != DEFAULT_VALUE; i++){
		for(int j = 0; j < MAX; j++){ //prepare for match!
			match[j] = DEFAULT_VALUE;
		}
		if(is_there_vaild_match(route[0][i])){
			add_answer(is_first_even ? odds[route[0][i]] : evens[route[0][i]]);
		}
	}
	
}

//OK : CHECKED
//more than 3~-> incoming numbers are all odd numbers
bool is_prime(int test_subject){
	//check if is dividable with all primes primes less than 43, if it's not, it's prime. 
	for(int i = 0; primes[i] <= test_subject && i < 14; i++){
		if(!(test_subject % primes[i])){ //this number is dividable with this prime probably not prime.
			if(test_subject != primes[i]){ //this number itself is not prime? complete non-prime number.
				return false;
			} else { //oh actually this is the prime itself.
				return true;
			}
		}
	}
	return true;
}

//probably fine...
void find_route(){
	for(int i = 0; i < N/2; i++){
		int route_count = 0;
		for(int j = 0; j < N/2; j++){
			if(is_first_even){
				if(is_prime(evens[i] + odds[j])){
					route[i][route_count] = j; //we should put the index number, not the node itself.
					route_count += 1;
				}
			} else { // first_odd
				if(is_prime(odds[i] + evens[j])){
					route[i][route_count] = j; //we should put the index number, not the node itself.
					route_count += 1;
				}
			}
		}
	}
}

int main ()
{
	int odd_count = 0, even_count = 0;
	scanf("%d", &N);
	
	//essential init
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			route[i][j] = DEFAULT_VALUE;
		}
	}
	memset(evens, 0, sizeof(evens));
	memset(odds, 0, sizeof(odds));
	memset(answer, 0, sizeof(answer));
	
	for(int i = 0; i < N; i++){
		int input = 0;
		scanf("%d", &input);
		if(odd_count == 0 && even_count == 0){
			if(input % 2 == 0)
				is_first_even = true;
			else
				is_first_even = false;
		}
		if(input % 2 == 0){
			evens[even_count] = input;
			even_count += 1;
		} else {
			odds[odd_count] = input;
			odd_count += 1;
		}
	}
	
	if(odd_count == N/2 && even_count == N/2){
		find_route(); //route setting done.
		extract_answer();
		print_answer();
	} else {
		printf("-1\n");
	}
	
	return 0;
}

