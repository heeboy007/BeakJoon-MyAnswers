#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int answer[8];
bool is_used[8];
int n, m;

void back_track(int level){
    if(level == m){
        for(int i = 0; i < m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if(is_used[i]){
            continue;
        }
        is_used[i] = true;
        answer[level] = i;
        back_track(level + 1);
        is_used[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    back_track(0);
    return 0;
}