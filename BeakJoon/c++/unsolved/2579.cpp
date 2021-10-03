#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int stairs[301], dp[301], con[301];
    int score = 0, n = 0;
    memset(dp, 0, sizeof(int) * 301);
    memset(con, 0, sizeof(int) * 301);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> stairs[i];
    
    dp[1] = stairs[1];
    stairs[0] = 0;

    for(int i = 2; i <= n; i++){
        
    }

    return 0;
}