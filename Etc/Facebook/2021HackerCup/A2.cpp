#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

vector<vector<int>> graph(26);
bool visited[26];

int bfs(int start, int dest){
    memset(visited, false, sizeof(bool) * 26);
    queue<int> q;
    int depth = 0, curr_nodes = 1, next_nodes = 0;
    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int where = q.front();
        q.pop();
        for(int node : graph[where]){
            if(node == dest){
                return depth + 1;
            } else if(visited[node]){
                continue;
            }
            q.push(node);
            visited[node] = true;
            next_nodes++;
        }
        curr_nodes--;
        if(!curr_nodes){
            curr_nodes = next_nodes;
            next_nodes = 0;
            depth++;
        }
    }
    return -1;
}

void app(int case_num){
    int ans = -1, k;
    string change;
    cin >> change >> k;

    for(int i = 0; i < 26; i++){
        graph[i].clear();
    }

    while(k--){
        string from_to;
        cin >> from_to;
        graph[from_to[0] - 'A'].push_back(from_to[1] - 'A');
    }

    for(char c = 'A'; c <= 'Z'; c++){
        int cal = 0;
        bool is_changeable = true;

        for(char from : change){
            if(c == from){
                continue;
            } else {
                int res = bfs(from - 'A', c - 'A');
                if(res < 0){
                    is_changeable = false;
                    break;
                }
                cal += res;
            }
        }

        if(!is_changeable)
            continue;
        
        if(ans < 0)
            ans = cal;
        else
            ans = min(ans, cal);
    }

    std::cout << "Case #" << case_num << ": " << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g;
    cin >> g;
    for(int i = 1; i <= g; i++){
        app(i);
    }

    return 0;
}