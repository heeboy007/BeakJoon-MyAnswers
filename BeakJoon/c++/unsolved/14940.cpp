#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int map[1005][1005];
int print[1005][1005];

#define P pair<int, int>

void bfs(P start_pos){
    int depth = 1, depth_size = 1;
    queue<P> q;
    q.push(start_pos);
    map[start_pos.first][start_pos.second] = 0;
    print[start_pos.first][start_pos.second] = 0;
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
            if(map[next.first][next.second]){
                q.push({next.first, next.second});
                map[next.first][next.second] = 0;
                print[next.first][next.second] = depth;
            }
        }
        depth_size--;
        if(!depth_size){
            depth_size = q.size();
            depth++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(print, -1, sizeof(print));

    int n, m;
    P start;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                start.first = i;
                start.second = j;
            } else if(!map[i][j]){
                print[i][j] = 0;
            }
        }
    }

    bfs(start);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << print[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}