/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int map[10005] = {0};
    int dp[10005][3] = {0};
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
    
    dp[0][0] = map[0];
    dp[0][1] = map[0];
    //cout << "dp 00: " << dp[0][0] << '\n';
    //cout << "dp 01: " << dp[0][1] << '\n';

    dp[1][0] = map[1];
    dp[1][1] = map[0] + map[1];
    //cout << "dp 10: " << dp[1][0] << '\n';
    //cout << "dp 11: " << dp[1][1] << '\n';

    dp[2][0] = map[0] + map[2];
    dp[2][1] = map[1] + map[2];
    //cout << "dp 20: " << dp[2][0] << '\n';
    //cout << "dp 21: " << dp[2][1] << '\n';
    
    for(int i = 3; i < n; i++){
        dp[i][0] = max(dp[i - 2][1] + map[i], max(dp[i - 3][0], dp[i - 3][1]) + map[i]);
        //cout << "dp " << i << "0: " << dp[i][0] << '\n';
        dp[i][1] = max(dp[i - 1][0] + map[i], max(dp[i - 3][0], dp[i - 3][1]) + map[i] + map[i - 1]);
        //cout << "dp " << i << "1: " << dp[i][1] << '\n';
    }
    
    int check = (n > 1 ? (int)max(dp[n - 2][0], dp[n - 2][1]) : 0);
    //int check = 0;
    
    cout << max(dp[n - 1][0], max(dp[n - 1][1], check));
    
    return 0;
}
