#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
char map[101][101];

void bfs(){
    queue<pair<int, int>> q;
    int depth = 0, prev_counter = 1, curr_counter = 0, min = 1000000;
    q.push({0, 0});
    map[0][0] = '0';
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        pair<int, int> check[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

        prev_counter -= 1;
        for(int i = 0; i < 4; i++){
            int cx = check[i].first, cy = check[i].second;
            bool valid = true;
            switch (i)
            {
            case 0:
                valid = (cx >= 0);
                break;
            case 1:
                valid = (cx <= n - 1);
                break;
            case 2:
                valid = (cy >= 0);
                break;
            case 3:
                valid = (cy <= m - 1);
                break;
            }
            if(valid){
                if(cx == (n - 1) && cy == (m - 1)){ // the end.
                    min = depth + 2 < min ? depth + 2 : min; 
                }
                if(map[cx][cy] == '1'){
                    q.push(check[i]);
                    map[cx][cy] = '0';
                    curr_counter += 1;
                }
            }
        }
        if(!prev_counter){
            depth += 1;
            prev_counter = curr_counter;
            curr_counter = 0;
        }
    }
    cout << min << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }

    bfs();

    return 0;
}