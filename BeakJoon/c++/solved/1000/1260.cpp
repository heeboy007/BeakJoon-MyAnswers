#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int dots, cons, start;
bool is_visited[1001];
int matrix[1001][1001];

/*
const int MAX = 1000 + 1;
int N, M, V;
int adjacent[MAX][MAX];
bool visited[MAX];
queue<int> q;

void DFS(int idx)
{
        cout << idx << " ";
        for(int i=1; i<=N; i++)
                 if (adjacent[idx][i] && !visited[i])
                 {
                         visited[i] = 1;
                         DFS(i);
                 }
}
*/

void dfs(int now){
    cout << now << ' ';
    for(int i = 1; i <= dots; i++){
        if(matrix[now][i] && !is_visited[i]){ //never visited
            is_visited[i] = true;
            dfs(i);
        }
    }
}

/*
void BFS(int idx)
{
        q.push(idx);
        visited[idx] = 1;

        while (!q.empty())
        {
                 idx = q.front();
                 q.pop();

                 cout << idx << " ";
                 for(int i=1; i<=N; i++)
                 if (adjacent[idx][i] && !visited[i])
                 {
                         visited[i] = 1;
                         q.push(i);
                 }
        }
}
*/

void bfs(int idx){
    queue<int> q;
    q.push(idx);
    is_visited[idx] = true;
    while(!q.empty()){
        idx = q.front();
        q.pop();
        cout << idx << ' ';

        for(int i = 1; i <= dots; i++){
            if(matrix[idx][i] && !is_visited[i]){ //never visited
                is_visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> dots >> cons >> start;

    for(int i = 0; i < cons; i++){
        int from, to;
        cin >> from >> to;

        matrix[from][to] = 1;
        matrix[to][from] = 1;
    }

    is_visited[start] = true;
    dfs(start);
    cout << endl;

    memset(is_visited, false, sizeof(bool) * 1005);
    bfs(start);
    cout << endl;

    return 0;
}

