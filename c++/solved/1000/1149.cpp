#include<iostream>

using namespace std;

int min(int a, int b){
    return a < b ? a : b;
}

int main(){
    int n;
    cin >> n;

    int cost[1000][3];
    int dp[2][3];
    int curr = 0;

    for(int i = 0; i < n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for(int i = 0; i < n; i++){
        int opp = curr ? 0 : 1;
        dp[opp][0] = min(dp[curr][1], dp[curr][2]) + cost[i][0];
        dp[opp][1] = min(dp[curr][0], dp[curr][2]) + cost[i][1];
        dp[opp][2] = min(dp[curr][0], dp[curr][1]) + cost[i][2];
        curr = opp;
    }

    cout << min(min(dp[curr][0], dp[curr][1]), dp[curr][2]);

    return 0;
}