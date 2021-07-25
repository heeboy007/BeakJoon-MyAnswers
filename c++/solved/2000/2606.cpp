#include<iostream>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;

vector<vector<int>> list;
bool is_visited[101];

void dfs(int curr){
    for(int i : list[curr]){
        if(!is_visited[i]){ //never visited
            is_visited[i] = true;
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(is_visited, false, sizeof(bool) * 101);

    int coms, cons;
    cin >> coms >> cons;
    list.resize(coms + 1);

    while(cons--){
        int from, to;
        cin >> from >> to;
        list[from].push_back(to);
        list[to].push_back(from);
    }
    is_visited[1] = true;
    dfs(1);

    int sum = coms - 1;
    for(int i = 2; i <= coms; i++){
        if(!is_visited[i])
            sum--;
    }

    cout << sum;

    return 0;
}