#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, curr = 4;
    vector<long long> P = {0, 1, 1, 1};
    cin >> n;

    while(n--){
        int input;
        cin >> input;
        for(int i = curr; i <= input; i++){
            P.push_back(P[i - 3] + P[i - 2]);
        }
        curr = input + 1 > curr ? input + 1 : curr;
        cout << P[input] << '\n';
    }

    return 0;
}