#include<iostream>
#include<cstring>

#define MOD 1000000009

using namespace std;
int map[3000][3000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    char input;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        memset(map[i], 0, sizeof(int) * m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input;
            switch (input)
            {
            case 'B':
                map[i + 1][j] += (map[i][j] + 1) % MOD;
                map[i + 1][j] %= MOD;
                map[i][j + 1] += (map[i][j] + 1) % MOD;
                map[i][j + 1] %= MOD;
                break;
            case 'E':
                map[i][j + 1] += (map[i][j] + 1) % MOD;
                map[i][j + 1] %= MOD;
                break;
            case 'S':
                map[i + 1][j] += (map[i][j] + 1) % MOD;
                map[i + 1][j] %= MOD;
                break;
            case 'X':
                cout << (map[i][j] + 1) % MOD;
                return 0;
            }
        }
    }
    
    return 0;
}