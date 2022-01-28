#include<iostream>

using namespace std;

void prob(){
    int n;
    cin >> n;
    int arr1[n] = { 0 }, arr2[n] = { 0 };
    int real_max = 0, other_max = 0;
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    for(int i = 0; i < n; i++){
        real_max = max(max(arr1[i], arr2[i]), real_max);
        other_max = max(min(arr1[i], arr2[i]), other_max);
    }
    cout << real_max * other_max << '\n';
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