#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<string> s;
    vector<string> v;
    
    int n, m;
    cin >> n >> m;
    while(n--){
        string input;
        cin >> input;
        s.insert(input);
    }
    while(m--){
        string input;
        cin >> input;
        if(s.end() != s.find(input)){
            v.push_back(input);
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(string output : v){
        cout << output << '\n';
    }

    return 0;
}