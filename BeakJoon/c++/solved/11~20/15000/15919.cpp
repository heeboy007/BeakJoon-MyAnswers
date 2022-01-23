#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> dp[1001];
    vector<vector<int>> travels(1001);
    int n, m;
    cin >> n >> m;

    while(m--){
        int start, end;
        cin >> start >> end;
        travels[end].push_back(start);
    }

    dp[0].first = 0;
    dp[0].second = 0;

    int last = 0;
    for(int i = 1; i <= n; i++){
        if(!travels[i].empty()){
            int minimum = 1001;
            for(int start : travels[i]){
                for(int j = 1; j <= start; j++)
                    minimum = min(max(start - dp[j - 1].second - 1, dp[j - 1].first), minimum);
            }
            dp[i].first = minimum;
            dp[i].second = i;
        } else {
            dp[i] = dp[i - 1];
        }
    }

    int minimum = 1001;
    for(int j = 1; j <= n; j++)
        minimum = min(max(n - dp[j - 1].second, dp[j - 1].first), minimum);
    minimum = min(max(n - dp[n].second, dp[n].first), minimum);

    cout << minimum;

    return 0;
}