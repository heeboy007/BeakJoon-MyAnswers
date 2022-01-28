#include<iostream>

using namespace std;

void prob(){
    int n;
    cin >> n;
    int arr[n] = { 0 };
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int seed = arr[n - 1], length = 1, count = 0;
    while(true){
        if(arr[n - length] == seed){
            length++;
        }
        else {
            length = 2 * (length - 1);
            if(n - length >= 0)
                arr[n - length] = seed;
            count++;
        }
        if(length > n)
            break;
    }
    cout << count << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        prob();
    }

    return 0;
}