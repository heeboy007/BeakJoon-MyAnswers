#include<iostream>

using namespace std;

int grid[15][15];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i < 15; i++){
        grid[0][i] = i;
    }

    for(int i = 1; i < 15; i++){
        int sum = 0;
        for(int j = 1; j < 15; j++){
            sum += grid[i - 1][j];
            grid[i][j] = sum;
        }
    }

    int TC;
    cin >> TC;
    for(int i = 0; i < TC; i++){
        int k, n;
        cin >> k >> n;
        cout << grid[k][n] << '\n';
    }

    return 0;
}