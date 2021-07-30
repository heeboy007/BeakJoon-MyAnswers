#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int> counter;
    vector<string> unique;
    string answer;
    int n, max = 0;
    cin >> n;

    while(n--){
        string input;
        cin >> input;
        if(!counter[input]){
            unique.push_back(input);
        }
        counter[input] += 1;
    }

    sort(unique.rbegin(), unique.rend());

    for(string node : unique){
        if(counter[node] >= max){
            max = counter[node];
            answer = node;
        }
    }

    cout << answer;

    return 0;
}