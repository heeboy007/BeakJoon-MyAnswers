#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
int map[301][301];
bool is_visited[301][301];

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    is_visited[sx][sy] = true;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        pair<int, int> check[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

        for(int i = 0; i < 4; i++){
            int cx = check[i].first, cy = check[i].second;
            if(map[cx][cy]){
                if(!is_visited[cx][cy]){
                    q.push(check[i]);
                    is_visited[cx][cy] = true;
                }
            } else {
                if(!is_visited[cx][cy] && map[x][y])
                    map[x][y] -= 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int input;
            cin >> input;
            map[i][j] = input;
        }
        memset(is_visited[i], false, sizeof(bool) * 301);
    }

    for(int melt = 0; true; melt++){
        bool melt_once = true;
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(!is_visited[i][j] && map[i][j]){
                    if(melt_once){
                        bfs(i, j);
                        melt_once = false;
                    }
                    else{
                        cout << melt;
                        return 0;
                    }
                }
            }
        }
        if(melt_once)
            break;
        for(int i = 0; i < n; i++)
            memset(is_visited[i], false, sizeof(bool) * 301);
    }

    cout << "0\n";
    return 0;
}