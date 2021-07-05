#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int curr = 2; curr <= n; curr++){
        while(!(n % curr)){
            n /= curr;
            cout << curr << '\n';
        }
    }
    
    return 0;
}