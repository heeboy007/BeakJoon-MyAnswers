#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define P pair<int, int>

vector<vector<P>> conn(20005);
int is_visited[20005];

#define INF 1e9

/*struct comp{
    bool operator()(P a, P b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};*/

void dijkstra(int start){
    priority_queue<P> pq;
    pq.push({0, start});
    is_visited[start] = 0;
    
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(is_visited[now] < dist)
            continue;
        
        for(P node : conn[now]){
            int cost = node.second + dist;
            //different than bfs... is vistied needs to be less than cost...
            if(cost < is_visited[node.first]){
                is_visited[node.first] = cost;
                pq.push({-cost, node.first});
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
    
    fill(is_visited, is_visited + 20005, INF);
    dijkstra(s);
    
    for(int k = 1; k <= n; k++){
        if(is_visited[k] == INF)
            cout << "INF\n";
        else
            cout << is_visited[k] << '\n';
    }
    
	return 0;
}
