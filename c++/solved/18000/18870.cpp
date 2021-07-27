#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, min = 1000000001, max = -1000000001;
    vector<int> sorted, copy;
    unordered_map<int, int> convert;
    cin >> n;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        sorted.emplace_back(input);
        copy.emplace_back(input);
    }
    sort(sorted.begin(), sorted.end());
    int prev = -1000000001, index = 0;
    for(int zip : sorted){
        if(zip != prev){
            convert[zip] = index;
            index++;
        }
        prev = zip;
    }
    for(int output : copy){
        cout << convert[output] << ' ';
    }

    return 0;
}