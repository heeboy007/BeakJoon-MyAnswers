#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
int degree[32500] = {0};
int result[32500] = {0};

void topologySort() {
    queue<int> q;
    
    //진입로가 없는 정점 전부 찾아서 넣어놓기
    for(int i = 1; i <= n; i++){
        if(!degree[i])
            q.push(i);
    }
    
    //모든 정점 순회
    for(int i = 1; i <= n; i++){
        //정점을 전부 순회하지 않았는데 큐가 비었다면 사이클이 있다는 뜻.
        if(q.empty()) {
            cout << "something is wrong" << endl;
            return;
        }
        
        //맨앞 정점을 뽑고 큐에서 제거, result에 기록
        int x = q.front();
        q.pop();
        cout << x << ' ';
        
        for(int y : graph[x]){
            degree[y]--;
            if(!degree[y])
                q.push(y);
        }
    }
    
    /*for(int res : result){
        cout << res << ' ';
    }*/
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    graph.resize(n + 1);
    
    for(int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        ++degree[to];
        graph[from].push_back(to);
    }
    
    topologySort();
    
    return 0;
}
