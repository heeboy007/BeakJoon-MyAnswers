#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        v.push_back(input);
    }
    sort(v.rbegin(), v.rend());

    for(int i = 0; i < n - 2; i++){
        int a = v[i], b = v[i + 1], c = v[i + 2];
        if(b + c > a){
            cout << a + b + c;
            return 0;
        }
    }
    cout << "-1";

    return 0;
}