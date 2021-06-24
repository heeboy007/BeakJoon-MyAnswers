#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>

using namespace std;

typedef pair<int,int> Cord;

bool compare(Cord a, Cord b){
    if(a.second == b.second){
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    vector<Cord> cords;
    cin >> count;

    for(int i = 0; i < count; i++){
        Cord p;
        cin >> p.first >> p.second;
        cords.push_back(p);
    }

    sort(cords.begin(), cords.end(), compare);
    ostringstream output;

    for(Cord p : cords){
        output << p.first << ' ' << p.second << '\n';
    }
    cout << output.str();

    return 0;
}