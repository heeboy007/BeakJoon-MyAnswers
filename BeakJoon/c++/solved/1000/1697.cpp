#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

#define MAX 100000

using namespace std;

bool visited[MAX + 1];
int counter[MAX + 1];

int bfs(int start, int target){
    int depth = 0;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    counter[depth] = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now == target)
            break;
        int check[3];
        check[0] = now - 1;
        check[1] = now + 1;
        check[2] = now * 2;
        for(int i = 0; i < 3; i++){
            if(0 <= check[i] && check[i] <= MAX){
                int next = check[i];
                if(visited[next])
                    continue;
                q.push(next);
                visited[next] = true;
                counter[depth + 1]++;
            }
        }
        counter[depth]--;
        if(!counter[depth])
            depth++;
    }
    return depth;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int start, target;
    cin >> start >> target;

    cout << bfs(start, target);

    return 0;
}