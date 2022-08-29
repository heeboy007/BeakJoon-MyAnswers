#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> primes = {2, 3, 5, 7};
    vector<long long> sum_primes;
    cin >> n;
    
    //range of this?? no idea realy
    for(int i = 11; i <= 15000000; i += 2){
        bool is_prime = true;
        for(int p : primes){
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
    
    long long sum = 0;
    sum_primes.push_back(0);
    for(int i = 0; i < primes.size(); i++){
        sum += primes[i];
        sum_primes.push_back(sum);
        //cout << sum << '\n';
    }
    int sums_size = sum_primes.size();
    
    int count = 0;
    for(int i = 0; i < sums_size; i++){
        //cout << sum_primes[i] - n << '\n';
        if(binary_search(sum_primes.begin(), sum_primes.end(), sum_primes[i] - n))
            count++;
    }
    cout << count;
    
    return 0;
}