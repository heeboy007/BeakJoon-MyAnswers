#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, k = 0, ans = 1; 
    cin >> n;
    cin >> k;

    for(int i = n; i > n - k; i--)
        ans *= i;

    for(int i = 1; i <= k; i++)
        ans /= i;
    
    cout << ans;

    return 0;
}