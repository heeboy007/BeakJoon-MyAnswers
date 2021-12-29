#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<pair<int, int>> v;
    vector<string> names;
    cin >> n;

    for(int i = 0; i < n; i++){
        pair<int, int> p;
        string name;
        cin >> p.first;
        p.second = i;
        cin >> name;
        v.push_back(p);
        names.push_back(name);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        cout << v[i].first << ' ' << names[v[i].second] << '\n';
    }

    return 0;
}