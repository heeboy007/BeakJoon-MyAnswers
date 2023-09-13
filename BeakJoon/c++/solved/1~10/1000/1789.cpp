#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long S;
    cin >> S;
    
    long long n = 2, sum = 1;
    while(true){
        if(S - sum  - n < 0){
            cout << n - 1;
            return 0;
        }
        sum += n;
        n++;
    }

    return 0;
}