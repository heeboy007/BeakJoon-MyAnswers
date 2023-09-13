#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long dp[95];
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    cin >> n;

    for(int i = 4; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];

    return 0;
}