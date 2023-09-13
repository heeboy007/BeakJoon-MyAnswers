#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long map[105][105] = {0};
    long long dp[105][105] = {0};

    int n;
    cin >> n;

    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < i; k++){
                if(map[k][j] == i - k && dp[k][j])
                    dp[i][j] += dp[k][j];
            }
            for(int k = 0; k < j; k++){
                if(map[i][k] == j - k && dp[i][k])
                    dp[i][j] += dp[i][k];
            }
            //cout << dp[i][j] << ' ';
        }
        //cout << '\n';
    }

    cout << dp[n - 1][n - 1];

    return 0;
}