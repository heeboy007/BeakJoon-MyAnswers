#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define P pair<int, int>

vector<vector<P>> conn;
int is_visited[20005];

struct comp{
    bool operator()(P a, P b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

void bfs(int start){
    priority_queue<P, vector<P>, comp> pq;
    pq.push({0, start});
    memset(is_visited, -1, sizeof(is_visited));
    is_visited[start] = 0;
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        for(P n : conn[p.second]){
            if(is_visited[n.first] == -1){
                is_visited[n.first] = p.first + n.second;
                pq.push({p.first + n.second, n.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, e, s, from, to, cost;
    cin >> n >> e >> s;
    conn.resize(n);
    while(e--){
        cin >> from >> to >> cost;
        conn[from].push_back({to, cost});
    }
    
    //bfs(s);
    
    for(int k = 1; k <= n; k++){
        if(is_visited[k] == -1)
            cout << "INF\n";
        else
            cout << is_visited[k] << '\n';
    }
    
	return 0;
}
