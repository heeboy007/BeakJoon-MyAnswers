#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, gm = 0;
    int ai[1001] = {0};
    int dp[1001] = {0};
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> ai[i];
    }
    for(int i = 0; i < n; i++)
    {
        int maximum = ai[i];
        for(int j = 0; j < i; j++){
            if(ai[j] < ai[i])
                maximum = max(maximum, dp[j] + ai[i]);
        }
        dp[i] = maximum;
        gm = max(maximum, gm);
    }
    cout << gm;

    return 0;
}