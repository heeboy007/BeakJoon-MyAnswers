#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    static char map[3001][3001];
    static int valid[3001][3001];

    int n, m; 
    long sum;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
    sum = n * m;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            if(map[i][j] == 'W' && map[i][j + 1] == 'B' && map[i + 1][j] == 'B' && map[i + 1][j + 1] == 'W'){
                valid[i][j] = 1;
            } else if(map[i][j] == 'B' && map[i][j + 1] == 'W' && map[i + 1][j] == 'W' && map[i + 1][j + 1] == 'B'){
                valid[i][j] = 1;
            } else {
                valid[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            if(valid[i][j] && i != 0 && j != 0){
                valid[i][j] = min(valid[i - 1][j], min(valid[i][j - 1], valid[i - 1][j - 1])) + 1;
            }
            sum += (long)valid[i][j];
        }
    }

    cout << sum;

    return 0;
}