#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 101

using namespace std;

int n;
char image [MAX][MAX];
bool is_visited[MAX][MAX];

bool is_in_range(int cx, int cy){
    return (0 <= cx) && (cx < n) && (0 <= cy) && (cy < n);
}

void bfs(int sx, int sy, bool color_blind){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    is_visited[sx][sy] = true;
    char area = image[sx][sy];
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        pair<int, int> check[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};
        for(int i = 0; i < 4; i++){
            int cx = check[i].first, cy = check[i].second;
            if(is_in_range(cx, cy)){
                if(is_visited[cx][cy])
                    continue;
                bool same_area = (image[cx][cy] == area);
                if(color_blind && area != 'B')
                    same_area = (image[cx][cy] != 'B');
                if(same_area){
                    q.push(check[i]);
                    is_visited[cx][cy] = true;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> image[i];
        memset(is_visited[i], false, sizeof(bool) * MAX);
    }

    int count_color_blind = 0, count_normal = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!is_visited[i][j]){
                bfs(i, j, false);
                count_normal++;
            }
        }
    }

    for(int i = 0; i < n; i++)
        memset(is_visited[i], false, sizeof(bool) * MAX);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!is_visited[i][j]){
                bfs(i, j, true);
                count_color_blind++;
            }
        }
    }

    cout << count_normal << ' ' << count_color_blind << '\n';

    return 0;
}