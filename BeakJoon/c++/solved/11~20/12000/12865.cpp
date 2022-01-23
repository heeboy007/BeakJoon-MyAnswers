#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> stuffs[100];
    int n, k;

    cin >> n >> k;
    
    vector<int> dp1(k + 1, 0), dp2(k + 1, 0);

    for(int i = 0; i < n; i++){
        pair<int, int> p;
        // Weight Value
        cin >> p.first >> p.second;
        stuffs[i] = p;
    }

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(!(i % 2)){
                if(j - stuffs[i].first < 0){
                    dp1[j] = dp2[j];
                } else {
                    dp1[j] = max(dp2[j - stuffs[i].first] + stuffs[i].second, dp2[j]);
                }
            } else {
                if(j - stuffs[i].first < 0){
                    dp2[j] = dp1[j];
                } else {
                    dp2[j] = max(dp1[j - stuffs[i].first] + stuffs[i].second, dp1[j]);
                }
            }
        }
    }
    if(!(n % 2)){
        cout << dp2[k];
    } else {
        cout << dp1[k];
    }

    return 0;
}