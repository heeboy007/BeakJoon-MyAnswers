#include<iostream>
#include<vector>
#include<algorithm>

#define DIV 29
#define DIV2 31
#define ll long long

using namespace std;

ll myhash(string s){
    ll hash = 0;
    for(char c : s){
        hash = hash * DIV + c - 'a' + 1;
    }
    return hash;
}

ll myhash2(string s){
    ll hash = 0;
    for(char c : s){
        hash = hash * DIV2 + c - 'a' + 1;
    }
    return hash;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<string> no_d, no_b, no_db;
    vector<ll> no_d_h, no_b_h;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        no_d.push_back(input);
        no_d_h.push_back(myhash(input));
    }
    for(int i = 0; i < m; i++){
        string input;
        cin >> input;
        no_b.push_back(input);
        no_b_h.push_back(myhash(input));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(no_d_h[i] == no_b_h[j]){
                no_db.push_back(no_b[j]);
                break;
            }
        }
    }

    sort(no_db.begin(), no_db.end());
    cout << no_db.size() << '\n';
    for(string s : no_db){
        cout << s << '\n';
    }

    return 0;
}