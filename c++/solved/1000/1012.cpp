#include<iostream>
#include<vector>

using namespace std;

bool map[52][52];

void spread(int x, int y){
    map[x][y]=false;
    if(map[x + 1][y])
        spread(x + 1, y);
    if(map[x][y + 1])
        spread(x, y + 1);
    if(map[x - 1][y])
        spread(x - 1, y);
    if(map[x][y - 1])
        spread(x, y - 1);
}

void app(){

    int m, n, k, count = 0;
    cin >> m >> n >> k;
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        map[x + 1][y + 1] = true;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(map[i][j]){
                spread(i, j);
                count++;
            }
        }
    }
    
    cout << count << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        app();
    }

    return 0;
}