#include<iostream>
#include<cstring>

#define MOD 1000000009

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n == 1){
        cout << "0\n";
        return 0;
    }
    
    long sum = 2;
    n -= 2;
    while(n--){
        sum = (sum % MOD * 3) % MOD;
    }

    cout << sum;

    return 0;
}