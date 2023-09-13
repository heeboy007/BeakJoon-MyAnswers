#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> conn_list(105);
bool is_visited[105];

void bfs(){
    queue<int> q;
    q.push(1);
    is_visited[1] = true;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : conn_list[curr]){
            if(is_visited[next])
                continue;
            q.push(next);
            is_visited[next] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, from, to, count = 0;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        cin >> from >> to;
        conn_list[from].push_back(to);
        conn_list[to].push_back(from);
    }

    bfs();
    for(int i = 2; i <= n; i++){
        if(is_visited[i])
            count++;
    }
    cout << count;

    return 0;
}