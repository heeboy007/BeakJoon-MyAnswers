#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct NODE{
    int first;
    int second;
    int breakable;
} P;

int n, m;
int map[1005][1005] = {0};
int is_visited[1005][1005] = {0};

int bfs(){
    int cal_depth = 99999999;
    int depth = 1;
    int x, y, px, py;
    bool br;
    P curr;
    queue<P> q;
    q.push({1, 1, true});
    is_visited[1][1] = 1;
    while(!q.empty()){
        int level_size = q.size();
        while(level_size--){
            curr = q.front();
            x = curr.first, y = curr.second;
            br = curr.breakable;
            q.pop();
            if(x == n && y == m)
                cal_depth = min(depth, cal_depth);
            P near[4] = {
                {x - 1, y, br},
                {x, y - 1, br},
                {x + 1, y, br},
                {x, y + 1, br}
            };
            for(int i = 0; i < 4; i++){
                px = near[i].first, py = near[i].second;
                if(is_visited[px][py] == 0 || depth <= is_visited[px][py]){
                    if(!map[px][py]){
                        is_visited[px][py] = depth;
                        q.push({px, py, curr.breakable});
                    } else if(curr.breakable && map[px][py] == 1) {
                        is_visited[px][py] = depth;
                        q.push({px, py, false});
                    }
                }
            }
        }
        depth++;
    }
    if(cal_depth == 99999999)
        return -1;
    return cal_depth;
}

int main() {
    memset(map, -1, sizeof(map));
    string str;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str;
        for(int j = 1; j <= m; j++){
            map[i][j] = str[j - 1] - '0';
        }
    }
    
    cout << bfs();
	return 0;
}