#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0; 
    cin >> count;

    vector<int> arr(count, 0);

    for(int i = 0; i < count; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int output : arr){
        cout << output << '\n';
    }
    return 0;
}