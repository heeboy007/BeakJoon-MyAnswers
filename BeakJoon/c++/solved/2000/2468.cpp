#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int map[101][101];
bool is_visited[101][101];

void bfs(int x, int y, int rain){
    queue<pair<int, int>> q;
    q.push({x, y});
    is_visited[x][y] = true;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

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
                valid = (cy <= n - 1);
                break;
            }
            if(valid){
                if(!is_visited[cx][cy] && map[cx][cy] > rain){
                    q.push(check[i]);
                    is_visited[cx][cy] = true;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sectors;

    int max_islands = 1, max = 0, min = 101;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int input;
            cin >> input;
            max = (input > max ? input : max);
            min = (input < min ? input : min);
            map[i][j] = input;
        }
        memset(is_visited[i], false, sizeof(bool) * 101);
    }

    for(int rain = min; rain <= max; rain++){
        int islands = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!is_visited[i][j] && map[i][j] > rain){
                    bfs(i, j, rain);
                    islands += 1;
                }
            }
        }
        max_islands = (islands > max_islands ? islands : max_islands);
        for(int i = 0; i < n; i++)
            memset(is_visited[i], false, sizeof(bool) * 101);
    }
    
    cout << max_islands;
    return 0;
}