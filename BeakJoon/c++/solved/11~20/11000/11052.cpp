#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int p[1001] = {0}, dp[1001] = {0};
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    //카드를 i 장 샀을때 최대 가격
    dp[1] = p[1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = max(dp[i - j] + p[j], dp[i]);
        }
    }
    cout << dp[n];

    return 0;
}