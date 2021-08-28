#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<string> v;
    map<string, int> om;

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        om[input] = i + 1;
        v.push_back(input);
    }
    while(m--){
        string input;
        cin >> input;
        if('0' <= input[0] && input[0] <= '9'){ //Number
            cout << v[stoi(input) - 1] << '\n';
        } else { //Name
            cout << om[input] << '\n';
        }
    }

    return 0;
}