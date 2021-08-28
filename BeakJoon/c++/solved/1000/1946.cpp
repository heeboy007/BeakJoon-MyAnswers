#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(b.first == a.first)
        return b.second > a.second;
    else
        return b.first > a.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int big_n = 0;
    cin >> big_n;

    for(int x = 0; x < big_n; x++){
        int n = 0, ans = 0;
        vector<pair<int, int>> scores; 
        cin >> n;

        for(int i = 0; i < n; i++){
            int start, end;
            cin >> start >> end;
            scores.push_back({start, end});
        }
        sort(scores.begin(), scores.end(), compare);

        int cutline = scores.front().second;

        for(int i = 0; i < scores.size(); i++){
            if(cutline < scores[i].second){
                ans += 1; //dropped
            } else {
                cutline = scores[i].second; //ok
            }
        }

        cout << scores.size() - ans << '\n';
    }

    return 0;
}