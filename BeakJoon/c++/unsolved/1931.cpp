#include<iostream>
#include<algorithm>

#define P pair<int, int>

using namespace std;

bool compare(P a, P b){
    if(b.second == a.second)
        return b.first > a.first;
    else
        return b.second > a.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    P meetings[n];
    for(int i = 0; i < n; ++i)
        cin >> meetings[i].first >> meetings[i].second;
    sort(meetings, meetings + n, compare);

    int next = 0, count = 0;
    for(int i = 0; i < n; ++i){
        if(next <= meetings[i].first){
            next = meetings[i].second;
            count++;
        }
    }
    cout << count;

    return 0;
}