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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, count = 0;
    vector<ll> no_d_h;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        no_d_h.push_back(myhash(input));
    }
    for(int i = 0; i < m; i++){
        string input;
        cin >> input;
        ll what = myhash(input);
        for(int j = 0; j < n; j++){
            if(no_d_h[j] == what){
                count++;
                break;
            }
        }
    }
    
    cout << count;

    return 0;
}