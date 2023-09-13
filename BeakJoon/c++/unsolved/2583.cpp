#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

#define P pair<int, int>

bool map[105][105] = {0};

int bfs(P start_pos){
    //bool map[105][105];
    int count = 1;
    queue<P> q;
    q.push(start_pos);
    map[start_pos.first][start_pos.second] = false;
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
                map[next.first][next.second] = false;
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, rects;
    cin >> n >> m >> rects;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            map[i][j] = true;

    while(rects--){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x++, y++, a++, b++;
        for(int i = x; i < a; i++)
            for(int j = y; j < b; j++)
                map[i][j] = false;
    }

    vector<int> areas;

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            if(map[i][j])
                areas.push_back(bfs({i, j}));

    sort(areas.begin(), areas.end());
    cout << areas.size() << '\n';
    for(int area : areas){
        cout << area << ' ';
    }

    return 0;
}