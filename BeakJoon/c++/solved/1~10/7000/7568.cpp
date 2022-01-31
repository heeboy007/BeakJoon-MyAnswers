#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> arr[51];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i = 0; i < n; i++){
        int count = 1;
        for(int j = 0; j < n; j++){
            if(arr[j].first > arr[i].first && arr[j].second > arr[i].second)
                count++;
        }
        cout << count << ' ';
    }

    return 0;
}