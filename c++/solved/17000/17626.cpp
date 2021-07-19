#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[50001];
    vector<int> blocks;
    int n = 1;

    memset(arr, 0, sizeof(arr));
    while(n * n < 50001){
        blocks.push_back(n * n);
        n++;
    }
    cin >> n;

    for(int i = 1; i <= n; i++){
        int min = 5;
        for(int block : blocks){
            if(i - block < 0){
                break;
            }
            if(arr[i - block] < min){
                min = arr[i - block];
            }
            arr[i] = min + 1;
        }
    }

    cout << arr[n];

    return 0;
}