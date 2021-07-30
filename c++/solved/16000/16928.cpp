#include<iostream>
#include<queue>
#include<unordered_map>
#include<cstring>

using namespace std;

unordered_map<int, int> ladder, snake;
bool is_visited[101];

void bfs(){
    queue<int> q;
    int depth = 1, curr_depth = 1, next_depth = 0;
    q.push(1);
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        for(int i = 1; i <= 6; i++){
            int curr = pos + i, next;
            if(curr == 100){
                cout << depth;
                return;
            }
            if(ladder[curr]){
                next = ladder[curr];
            } else if(snake[curr]){
                next = snake[curr];
            } else {
                next = curr;
            }
            if(!is_visited[next]){
                next_depth++;
                q.push(next);
                is_visited[next] = true;
            }
        }
        if(!(--curr_depth)){
            depth++;
            curr_depth = next_depth;
            next_depth = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(is_visited, false, sizeof(bool) * 101);

    int n, m;
    cin >> n >> m;
    while(n--){
        int from, to;
        cin >> from >> to;
        ladder[from] = to;
    }
    while(m--){
        int from, to;
        cin >> from >> to;
        snake[from] = to;
    }

    bfs();

    return 0;
}