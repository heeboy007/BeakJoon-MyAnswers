#include<iostream>

using namespace std;

int main(){

    bool deleted[1001];
    int curr = 2, n, k;
    int count = 0;

    cin >> n >> k;

    for(int i = 0; i <= n; i++)
        deleted[i] = false;

    while(curr <= n){
        if(deleted[curr]){
            curr++;
            continue;
        }
            
        deleted[curr] = true;
        count++;
        if(count == k){
            cout << curr;
            return 0;
        }
            
        for(int i = curr * 2; i <= n; i = i + curr){
            if(deleted[i])
                continue;
            deleted[i] = true;
            count++;
            if(count == k){
                cout << i;
                return 0;
            }
        }
        curr++;
    }

    return 0;
}