#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> v;
    vector<string> names;
    unordered_map<int, int> map;
    cin >> n;

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        if(map.find(input) == map.end()){
            map[input] = 1;
        } else {
            map[input] = map[input] + 1;
        }
    }

    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        cout << map[input] << '\n';
    }

    return 0;
}