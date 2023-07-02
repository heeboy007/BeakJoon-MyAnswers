#include<iostream>
#include<vector>

using namespace std;

#define MOD 1000000000

int combination(int n, int k)
{
    std::vector<std::vector<int>> pascal(n + 1, std::vector<int>(k + 1, 0));
    
    for(int i = 0; i <= n; ++i){
        pascal[i][0] = 1;
    }
    
    for (int i = 1; i <= k; ++i) {
        pascal[0][i] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % MOD;
        }
    }

    return pascal[n][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << (k + n - 1) << '\n';
    cout << k << '\n';
    int res = combination(k + n - 1, n);
    cout << res;
  
    return 0;
}