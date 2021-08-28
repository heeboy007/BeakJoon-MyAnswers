#include<iostream>
#include<cstring>
#include<queue>

#define MAX 1001

using namespace std;

int dots;
bool is_visited[MAX];
int matrix[MAX][MAX];

void bfs(int idx){
    queue<int> q;
    q.push(idx);
    is_visited[idx] = true;
    while(!q.empty()){
        idx = q.front();
        q.pop();
        for(int i = 1; i <= dots; i++){
            if(matrix[idx][i] && !is_visited[i]){
                q.push(i);
                is_visited[i] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cons, count = 0;
    cin >> dots >> cons;

    while(cons--){
        int from, to;
        cin >> from >> to;

        matrix[from][to] = 1;
        matrix[to][from] = 1;
    }

    memset(is_visited, false, sizeof(bool) * MAX);

    for(int i = 1; i <= dots; i++){
        if(!is_visited[i]){
            bfs(i);
            count++;
        }
    }

    cout << count;

    return 0;
}