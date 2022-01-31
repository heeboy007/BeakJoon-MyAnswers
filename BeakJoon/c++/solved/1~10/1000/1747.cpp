#include<iostream>
#include<vector>

using namespace std;

bool is_pel(int num){
    int comp = 0, temp = num;
    while(temp){
        comp = comp * 10 + temp % 10;
        temp /= 10;
    }
    return comp == num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> primes;

    for(int i = 2; ; i++){
        bool is_sosu = true;
        for(int prime : primes){
            if(prime * prime > i)
                break;
            if(!(i % prime)){
                is_sosu = false;
                break;
            }
        }
        if(is_sosu){
            primes.emplace_back(i);
            if(i >= n){
                if(is_pel(i)){
                    cout << i;
                    return 0;
                }
            }
        }
    }

    return 0;
}