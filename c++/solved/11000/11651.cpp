#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if(b.first == a.first)
        return b.second > a.second;
    else
        return b.first > a.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0; 
    cin >> count;

    vector<pair<int, int>> arr(count);

    for(int i = 0; i < count; i++){
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), compare);

    for(pair<int, int> output : arr){
        cout << output.first << " " << output.second << '\n';
    }
    return 0;
}