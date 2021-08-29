#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long n, k;
        cin >> n >> k;

        k = min(n - 1, k);

        cout << (n * (n + 1) - (n - k - 1) * (n - k)) * 2 << '\n';
    }

    return 0;
}