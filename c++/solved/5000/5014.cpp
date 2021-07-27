#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

long bfs(long dots, long start, long dest, long up, long down){
    long depth = 0, prev_depth = 1, curr_depth = 0;
    bool is_visited[1000001];
    queue<int> q;
    
    memset(is_visited, false, sizeof(bool) * 1000001);
    q.push(start);
    is_visited[start] = true;
    
    while(!q.empty()){
        int dot = q.front();
        q.pop();
        if(dot == dest)
            return depth;
        if(dot + up <= dots){
            if(!is_visited[dot + up]){
                q.push(dot + up);
                curr_depth += 1;
                is_visited[dot + up] = true;
            }
        }
        if(dot - down > 0){
            if(!is_visited[dot - down]){
                q.push(dot - down);
                curr_depth += 1;
                is_visited[dot - down] = true;
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

    int dots, start, dest, up, down;
    cin >> dots >> start >> dest >> up >> down;

    long result = bfs(dots, start, dest, up, down);
    if(result >= 0){
        cout << result << '\n'; 
    } else {
        cout << "use the stairs\n";
    }

    return 0;
}