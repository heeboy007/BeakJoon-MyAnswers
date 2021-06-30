#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

bool visited[1001];
vector<int> list[1001];

void dfs(int now){
    if(visited[now])
        return;
    visited[now] = true;
    cout << now << ' ';
    for(int i = 0; i < list[now].size(); i++){
        int next = list[now][i];
        dfs(next);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now << ' ';
        for(int next : list[now]){
            if(visited[next])
                continue;
            q.push(next);
            visited[next] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, k, count = 0;
    cin >> n >> m >> k;
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        list[x].push_back(y);
        list[y].push_back(x);
    }

    for(int i = 0; i < n; i++){
        sort(list[i].begin(), list[i].end());
    }

    dfs(k);
    
    cout << '\n';
    memset(visited, 0, sizeof(visited));

    bfs(k);

    return 0;
}