#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> sums;

    sums.push_back(0);
    while(n--){
        int input;
        cin >> input;
        sum += input;
        sums.push_back(sum);
    }
    while(m--){
        int from, to;
        cin >> from >> to;
        cout << sums[to] - sums[from - 1] << '\n';
    }

    return 0;
}