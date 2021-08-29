#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

vector<vector<int>> graph(100001);
bool visited[100001];

//is this dfs though? Dunno.
vector<int> dfs(int start, bool selected){
    vector<int> res, pos, skip;
    visited[start] = true;
    
    if(selected){
        vector<int> q;

        for(int i = 0; i < graph[start].size(); i++){
            int elim = graph[start][i];
            if(visited[elim]){
                skip.push_back(0);
            } else {
                skip.push_back(elim);
            }
            visited[elim] = true;
        }
        
        for(int i = 0; i < graph[start].size(); i++){
            int elim = graph[start][i];
            if(elim == start)
                continue;
            for(int possible : graph[elim]){
                if(visited[possible] || find(q.begin(), q.end(), possible) != q.end())
                    continue;
                q.emplace_back(possible);
            }
        }

        for(int node : q){
            pos = dfs(node, true);
            if(pos.size() > res.size())
                res = pos;
            pos = dfs(node, false);
            if(pos.size() > res.size())
                res = pos;
        }

        res.emplace_back(start);
    } else {
        for(int elim : graph[start]){
            if(visited[elim])
                continue;
            pos = dfs(elim, true);
            if(pos.size() > res.size())
                res = pos;
            pos = dfs(elim, false);
            if(pos.size() > res.size())
                res = pos;
        }
    }
        
    visited[start] = false;
    if(selected){
        for(int i = 0; i < graph[start].size(); i++){
            int elim = graph[start][i];
            if(skip[i]){
                visited[elim] = false;
            }
        }
    }
    
    return std::move(res);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    while(M--){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    memset(visited, false, sizeof(bool) * N);
    vector<int> res = dfs(1, true);
    memset(visited, false, sizeof(bool) * N);
    vector<int> res2 = dfs(1, false);

    if(res2.size() > res.size())
        res = res2;

    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for(int node : res){
        cout << node << ' ';
    }

    return 0;
}