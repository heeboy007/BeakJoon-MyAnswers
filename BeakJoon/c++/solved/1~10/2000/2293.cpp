#include<iostream>
#include<cstring>

using namespace std;

// 점화식이 제대로 최적화가 안됬음. 동작은 하는데, 너무 느림.

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, curr = 0, old = 1, temp, coin;
    long long dp[2][10001];

    cin >> n >> k;

    memset(dp[0], 0, sizeof(dp[0]));
    memset(dp[1], 0, sizeof(dp[1]));
    
    //dp[i - 1 ~ i][j]는 i번째까지의 동전을 이용해 j원을 만드는 경우의 수
    for(int i = 0; i < n; i++){
        cin >> coin;
        for(int j = 1; j <= k; j++){
            dp[curr][j] = dp[old][j];
            if(!(j % coin))
                dp[curr][j]++;
            for(int x = 1; j - x * coin > 0; x++){ //index exists
                long long check = dp[old][j - x * coin];
                if(check){ //and it's not zero
                    dp[curr][j] += check;
                }
            }
        }
        temp = curr;
        curr = old;
        old = temp;
    }

    cout << dp[old][k];

    return 0;
}