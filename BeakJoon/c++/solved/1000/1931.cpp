#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(b.second == a.second)
        return b.first < a.first;
    else
        return b.second < a.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0, ans = 0;
    vector<pair<int, int>> meetings; 
    cin >> n;

    for(int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;
        meetings.push_back({start, end});
    }
    sort(meetings.begin(), meetings.end(), compare);

    int next_start = meetings.back().second;
    meetings.pop_back();
    ans += 1;

    while(!meetings.empty()){
        int start = meetings.back().first;
        int end = meetings.back().second;
        if(start < next_start){
            meetings.pop_back();
            continue;
        }
        next_start = end;
        ans += 1;
        meetings.pop_back();
    }

    cout << ans;

    return 0;
}