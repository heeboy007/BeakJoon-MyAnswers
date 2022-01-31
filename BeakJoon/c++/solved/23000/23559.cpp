#include<iostream>
#include<cmath>
#include<algorithm>

#define P pair<int, int>

using namespace std;

bool compare(P a, P b){
    return a.first - a.second > b.first - b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, money;
    cin >> n >> money;

    P food[n];
    for(int i = 0; i < n; i++)
        cin >> food[i].first >> food[i].second;
    sort(food, food + n, compare);

    int good = 0;
    int how_may_5000 = floor((money - 1000 * n) / 4000.f);
    for(int i = 0; i < n; i++){
        if(how_may_5000 > 0 && food[i].first > food[i].second){
            good += food[i].first;
            how_may_5000--;
        } else {
            good += food[i].second;
        }
    }
    cout << good;

    return 0;
}