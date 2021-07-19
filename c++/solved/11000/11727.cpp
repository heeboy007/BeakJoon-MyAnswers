#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dp[1001];
    int n;
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 3;
    
    cin >> n;

    for(int i = 3; i <= n; i++){
        dp[i] = (dp[i - 1] + (2 * dp [i - 2]) % 10007) % 10007;
    }
    cout << dp[n];

    return 0;
}