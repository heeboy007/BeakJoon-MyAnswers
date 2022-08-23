#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
1. ceil(sqrt(b))보다 작은 모든 소수를 구한다.
2. 그 소수들을 제곱한다.
3. 배열에 [a, b]까지의 모든 수의 배수 여부를 구해, true로 삽입한다.
4. true인 배열의 값을 전부 더한다.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	long long n, m;
	vector<long long> primes = {2, 3, 5 ,7};
    bool is_nonono[1000005] = {0};
	cin >> n >> m;
	
	int until = (int)ceil(sqrt(m));
	for(long long i = 11; i <= until; i += 2){
	    bool is_prime = true;
	    for(long long p : primes){
	        if(p * p > i)
	            break;
	        if(!(i % p)){
	            is_prime = false;
	            break;
	        }
	    }
	    if(is_prime)
	        primes.push_back(i);
	}
	
	int s = primes.size();
	for(int i = 0; i < s; i++){
	    primes[i] = primes[i] * primes[i];
	    //cout << primes[i] << '\n';
	}
	
	for(long long p : primes){
	    for(int index = (n + p - 1) / p; index * p <= m; index++)
	        is_nonono[index * p - n] = true;
	}
	
	int count = 0;
	for(int i = 0; i <= m - n; i++){
	    if(!is_nonono[i])
	        count++;
	}
	
	cout << count;
	return 0;
}
