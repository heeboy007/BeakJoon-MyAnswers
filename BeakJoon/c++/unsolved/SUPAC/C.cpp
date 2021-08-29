#include<iostream>
#include<vector>

using namespace std;

char map[3000][3000];
vector<vector<bool>> is_valid;
vector<vector<bool>> next_vaild;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, sum = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
    sum += n * m;

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            if(map[i][j] == 'W' && map[i][j + 1] == 'B' && map[i + 1][j] == 'B' && map[i + 1][j + 1] == 'W'){
                is_valid[i][j] = true;
            }
            else if(map[i][j] == 'B' && map[i][j + 1] == 'W' && map[i + 1][j] == 'W' && map[i + 1][j + 1] == 'B'){
                is_valid[i][j] = true;
            }
            else{
                is_valid[i][j] = false;
            }
        }
    }

    for(int l = 3; l < min(n, m); l++){
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m - 1; j++){
                
            }
        }
    }

    cout << sum;

    return 0;
}