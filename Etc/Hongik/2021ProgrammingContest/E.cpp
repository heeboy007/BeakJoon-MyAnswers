#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> adj_list(100001, vector<int>());
bool is_visited[100001];

long long bfs(int start){
    queue<int> q;
    q.push(start);
    is_visited[start] = true;
    long long cnt = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cnt++;
        for(int x : adj_list[now]){
            if(is_visited[x])
                continue;
            is_visited[x] = true;
            q.push(x);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    int sp_to, sp_from;

    for(int i = 0; i < m; i++){
        int to, from;
        cin >> to >> from;
        if(i == k - 1){
            sp_to = to;
            sp_from = from;
            continue;
        }
        adj_list[to].push_back(from);
        adj_list[from].push_back(to);
    }

    long long res = 0;
    for(int i = 1; i <= n; i++){
        if(is_visited[i])
            continue;
        long long temp = bfs(i);   
        if(res){
            if(is_visited[sp_from] && is_visited[sp_to]){
                cout << temp * res << '\n';
                return 0;
            }
        } else {
            if(is_visited[sp_from] ^ is_visited[sp_to])
                res = temp;
        }
    }

    cout << "0\n";
    return 0;
}