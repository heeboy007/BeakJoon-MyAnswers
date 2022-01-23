#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long dp[34] = { 0 };
    cin >> n;

    dp[2] = 3LL;
    dp[4] = 11LL;

    for(int i = 6; i <= n; i++){
        dp[i] = dp[i - 2] * dp[2] + dp[i - 4] * dp[4];
    }
    cout << dp[n];

    return 0;
}