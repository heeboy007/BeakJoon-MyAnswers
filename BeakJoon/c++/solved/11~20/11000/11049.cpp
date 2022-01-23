#include<iostream>

#define MY_MAX 2147483647LL
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll dp[505][505] = { {0} };
    pair<ll, ll> matrix[505];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> matrix[i].first >> matrix[i].second;
        for(int j = 0; j < n; j++)
            dp[i][j] = MY_MAX * 3LL;
        dp[i][i] = 0;
    }
    for(int i = 0; i < n - 1; i++){ //현재 돌리고 있는 dp j - i 차이
        for(int j = 0; j < n - i - 1; j++){ //현재 계산하고 있는 매트리스 몇 번째 인덱스
            ll curr = MY_MAX * 3LL;
            for(int k = 0; k <= i; k++){ // i ~ j 사이에서 곱해질 수 있는 모든 dp 계산
                curr = min(curr, matrix[j].first * matrix[j + k].second  * matrix[j + i + 1].second + dp[j][j + k] + dp[j + k + 1][j + i + 1]);
            }
            dp[j][j + 1 + i] = curr;
        }
    }
    cout << dp[0][n - 1];

    return 0;
}