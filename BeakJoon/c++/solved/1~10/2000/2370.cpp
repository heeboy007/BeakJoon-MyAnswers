#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>

using namespace std;

#define P pair<int, int>

//간격이 중요하지 않을때는 좌표압축을 이용한다.
void condense(vector<P> &org){
    vector<int> unique_elem;

    for(P p : org){
        unique_elem.push_back(p.first);
        unique_elem.push_back(p.second);
    }
    sort(unique_elem.begin(), unique_elem.end());
    unique_elem.erase(unique(unique_elem.begin(), unique_elem.end()), unique_elem.end());

    int idx = 1, length = org.size();
    for(int i = 0; i < length; i++){
        org[i].first = (lower_bound(unique_elem.begin(), unique_elem.end(), org[i].first) - unique_elem.begin()) + 1;
        org[i].second = (lower_bound(unique_elem.begin(), unique_elem.end(), org[i].second) - unique_elem.begin()) + 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<P> posters;
    int posted[20005] = { 0 };
    for(int i = 0; i < n; i++){
        P input;
        cin >> input.first >> input.second;
        posters.push_back(input);
    }
    //압축
    condense(posters);

    //시뮬레이션
    for(int i = 0; i < n; i++){
        for(int j = posters[i].first; j <= posters[i].second; j++){
            posted[j] = i + 1;
        }
    }
    set<int> check;
    for(int i = 1; posted[i]; i++){
        check.insert(posted[i]);
    }
    cout << check.size();

    return 0;
}