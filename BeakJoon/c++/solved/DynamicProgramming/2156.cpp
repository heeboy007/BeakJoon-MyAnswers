#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int map[10005] = {0};
    int dp[10005] = {0};
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
    
    dp[0] = map[0];
    dp[1] = map[0] + map[1];
    dp[2] = max(map[0] + map[2], max(dp[1], map[1] + map[2]));
    
    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i - 2] + map[i], 
            max(dp[i - 1], dp[i - 3] + map[i - 1] + map[i]));
    }
    
    cout << dp[n - 1];
    
    return 0;
}
