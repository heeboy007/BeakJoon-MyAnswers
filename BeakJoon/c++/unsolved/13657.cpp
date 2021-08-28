#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>

#define MAX_VERTICES 50001

using namespace std;

bool is_visited[MAX_VERTICES] = {false,};
int connection[MAX_VERTICES] = {0,};
//int min_cost[MAX_VERTICES] = {0,};
pair<int, int> result = {0, 0};
vector<vector<pair<int, int>>> graph_list(MAX_VERTICES, vector<pair<int, int>>());
//vector<unordered_map<int, pair<int, int>>> dp(MAX_VERTICES, unordered_map<int, pair<int, int>>());

void dfs(int prev, int point, int depth, int curr_cost){
    is_visited[point] = true;
    bool is_end = true;
    int size = graph_list[point].size();
    for(int i = 0; i < size; i++){
        pair<int, int> node = graph_list[point][i];
        if(is_visited[node.first])
            continue;
        dfs(point, node.first, depth + 1, curr_cost + node.second);
        is_end = false;
    }
    if(is_end){
        if(result.first < depth){
            result.first = depth;
            result.second = curr_cost;
        }
        else if(result.first == depth)
            result.second = (result.second < curr_cost ? result.second : curr_cost);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, mod;
    cin >> V >> mod;

    int to, temp;
    pair<int, int> from_cost;
    for(int i = 1; i < V; i++){
        cin >> to >> from_cost.first >> from_cost.second;
        connection[to] += 1;
        graph_list[to].emplace_back(from_cost);
        
        //SWAP
        temp = from_cost.first; from_cost.first = to; to = temp;
        
        connection[to] += 1;
        graph_list[to].emplace_back(from_cost);
    }

    for(int i = 1; i <= V; i++){
        if(connection[i] != 1)
            continue;
        memset(is_visited, false, sizeof(bool) * MAX_VERTICES);
        dfs(0, i, 0, 0);
    }

    //cout << result.first << ":" << result.second << endl;
    if(result.second % mod)
        cout << (result.second / mod) + 1;
    else
        cout << (result.second / mod);

    return 0;
}