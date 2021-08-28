#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, string> uo;
    int n, m;
    cin >> n >> m;
    while(n--){
        string key, value;
        cin >> key >> value;
        uo[key] = value;
    }
    while(m--){
        string key;
        cin >> key;
        cout << uo[key] << '\n';
    }

    return 0;
}