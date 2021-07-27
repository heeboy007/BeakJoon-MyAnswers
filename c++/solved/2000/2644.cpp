#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

int bfs(int start, int dest, vector<vector<int>> &graph){
    int depth = 0, prev_depth = 1, curr_depth = 0;
    bool is_visited[101];
    queue<int> q;
    
    memset(is_visited, false, sizeof(is_visited));
    q.push(start);
    is_visited[start] = true;
    while(!q.empty()){
        int dot = q.front();
        q.pop();
        if(dot == dest)
            return depth;
        for(int node : graph[dot]){
            if(!is_visited[node]){
                q.push(node);
                curr_depth += 1;
                is_visited[node] = true;
            }
        }
        if(!(--prev_depth)){
            depth += 1;
            prev_depth = curr_depth;
            curr_depth = 0;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int dots, start, dest, cons;
    cin >> dots >> start >> dest >> cons;
    vector<vector<int>> graph(dots + 1, vector<int>());

    while(cons--){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    cout << bfs(start, dest, graph);

    return 0;
}