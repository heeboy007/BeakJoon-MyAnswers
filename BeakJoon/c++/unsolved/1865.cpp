#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 10000000
#define P pair<pair<int, int>, int>

int n, m, w;
//int edge[505][505];
vector<P> edge;
int dist[505];

void bellman_ford(){
    dist[1] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(int j = 0; j < edge.size(); j++){
            int from = edge[j].first.first;
            int to = edge[j].first.second;
            int cost = edge[j].second;
            
            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
        }
    }
    
    for(int j = 0; j < edge.size(); j++){
        int from = edge[j].first.first;
        int to = edge[j].first.second;
        int cost = edge[j].second;
        
        if(dist[from] == INF) continue;
        if(dist[to] > dist[from] + cost){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int x, y;

bool is_that(P p){
    return (p.first.first == x && p.first.second == y);
}

void push(int a, int b, int cost){
    x = a, y = b;
    auto it = find_if(edge.begin(), edge.end(), is_that);
    if(it == edge.end())
        edge.push_back({{a, b}, cost});
    else
        (*it).second = min((*it).second, cost);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    int tc;
    cin >> tc;
    
    while(tc--){
        cin >> n >> m >> w;
        
        edge.clear();
        //edge.resize(505);
        fill(dist, dist + 505, INF);
        
        while(m--){
          int a, b, cost;
          cin >> a >> b >> cost;
          push(a, b, cost);
          push(b, a, cost);
        }
        while(w--){
          int a, b, cost;
          cin >> a >> b >> cost;
          push(a, b, -cost);
        }
        
        bellman_ford();
    }
    
  
    return 0;
}