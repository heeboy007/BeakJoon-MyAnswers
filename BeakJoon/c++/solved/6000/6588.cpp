#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool is_prime[1000001];
vector<long> primes;

void prime_load(){
    for(long i = 3; i <= 1000000; i += 2){
        bool check_prime = true;
        for(long prime : primes){
            if(i < prime * prime)
                break;
            if(!(i % prime)){
                check_prime = false;
                break;
            }
        }
        if(check_prime){
            primes.push_back(i);
            is_prime[i] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(is_prime, false, sizeof(is_prime));
    prime_load();

    int t;
    cin >> t;
    while(t){
        for(long prime : primes){
            if(is_prime[t - prime]){
                cout << t << " = " << prime << " + " << (t - prime) << '\n';
                break;
            }
        }
        cin >> t;
    }

    return 0;
}