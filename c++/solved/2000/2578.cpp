#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

//try to use dfs instead of bfs

int n, m;
int map[101][101];

int dfs(int x, int y){
    int counter = 1;
    map[x][y] = 1;
    pair<int, int> check[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
    for(int i = 0; i < 4; i++){
        int cx = check[i].first, cy = check[i].second;
        bool valid = true;
        switch (i)
        {
        case 0:
            valid = (cx >= 0);
            break;
        case 1:
            valid = (cx <= n - 1);
            break;
        case 2:
            valid = (cy >= 0);
            break;
        case 3:
            valid = (cy <= m - 1);
            break;
        }
        if(valid){
            if(!map[cx][cy]){
                counter += dfs(cx, cy);
            }
        }
    }
    return counter;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sectors;

    int k;
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++)
        memset(map, 0, sizeof(int) * 101);

    while(k--){
        int ax, ay, bx, by;
        cin >> ay >> ax >> by >> bx;
        for(int i = ax; i < bx; i++){
            for(int j = ay; j < by; j++){
                map[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!map[i][j]){
                sectors.push_back(dfs(i, j));
            }
        }
    }
    
    sort(sectors.begin(), sectors.end());

    cout << sectors.size() << '\n';
    for(int sec_size : sectors){
        cout << sec_size << ' ';
    }

    return 0;
}