#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

#define P pair<int, int>

char map[105][105] = {0};
bool is_visited[105][105] = {0};

void bfs(P start_pos, bool is_blind){
    queue<P> q;
    q.push(start_pos);
    char area = map[start_pos.first][start_pos.second];
    is_visited[start_pos.first][start_pos.second] = true;
    is_blind = is_blind && (area == 'R' || area == 'G');
    while(!q.empty()){
        P curr = q.front();
        q.pop();
        vector<P> adj = {
            {curr.first - 1, curr.second},
            {curr.first + 1, curr.second},
            {curr.first, curr.second - 1},
            {curr.first, curr.second + 1},
        };
        for(P next : adj){
            bool pass = is_blind && (map[next.first][next.second] == (area == 'R' ? 'G' : 'R'));
            if(area == map[next.first][next.second] || pass){
                if(!is_visited[next.first][next.second]){
                    q.push({next.first, next.second});
                    is_visited[next.first][next.second] = true;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count_norm = 0, count_blind = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> map[i] + 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!is_visited[i][j]){
                bfs({i, j}, false);
                count_norm++;
            }
        }
    }

    memset(is_visited, 0, sizeof(is_visited));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!is_visited[i][j]){
                bfs({i, j}, true);
                count_blind++;
            }
        }
    }

    cout << count_norm << ' ' << count_blind;

    return 0;
}