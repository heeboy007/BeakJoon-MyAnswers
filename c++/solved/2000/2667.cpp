#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n;
char map[101][101];

int bfs(int x, int y){
    queue<pair<int, int>> q;
    int counter = 1;
    q.push({x, y});
    map[x][y] = '0';
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        pair<int, int> check[4] = {{x - 1, y}, {x + 1, y}, {x, y - 1}, {x, y + 1}};

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
                valid = (cy <= n - 1);
                break;
            }
            if(valid){
                if(map[cx][cy] == '1'){
                    q.push(check[i]);
                    map[cx][cy] = '0';
                    counter += 1;
                }
            }
        }
    }
    return counter;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sectors;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(map[i][j] == '1')
                sectors.push_back(bfs(i, j));

    sort(sectors.begin(), sectors.end());

    cout << sectors.size() << '\n';
    for(int houses : sectors){
        cout << houses << '\n';
    }

    return 0;
}