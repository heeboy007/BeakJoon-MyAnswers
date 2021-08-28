#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v = {0, 1, 2, 4, 7};

    for(int i = 5; i < 12; i++){
        long long sum = v[i - 3] + v[i - 2] + v[i - 1];
        v.push_back(sum);
    }
    int n;
    cin >> n;
    while(n--){
        int input;
        cin >> input;
        cout << v[input] << '\n';
    }

    return 0;
}