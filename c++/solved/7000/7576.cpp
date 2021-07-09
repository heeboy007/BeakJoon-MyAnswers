#include<iostream>
#include<queue>

#define MAX 1001

using namespace std;

int tray[MAX][MAX];

void add_cord_to_queue(queue<pair<int, int>> *q, int x, int y){
    tray[x][y] = 1;
    pair<int, int> cord;
    cord.first = x;
    cord.second = y;
    q->push(cord);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<pair<int, int>> q;
    int empty = 0, depth = -1; //which is the time.
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> tray[i][j];
            if(tray[i][j] > 0){
                pair<int, int> cord;
                cord.first = i;
                cord.second = j;
                q.push(cord);
                empty++;
            }
            else if(!tray[i][j]){
                empty++;
            }
        }
    }

    int curr_depth = q.size();
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x + 1 < m){ //valid
            if(tray[x + 1][y] == 0){ //is 0
                add_cord_to_queue(&q, x + 1, y);
            }
        }
        if(x - 1 >= 0){
            if(tray[x - 1][y] == 0){ //is 0
                add_cord_to_queue(&q, x - 1, y);
            }
        }
        if(y + 1 < n){ //valid
            if(tray[x][y + 1] == 0){ //is 0
                add_cord_to_queue(&q, x, y + 1);
            }
        }
        if(y - 1 >= 0){
            if(tray[x][y - 1] == 0){ //is 0
                add_cord_to_queue(&q, x, y - 1);
            }
        }
        curr_depth--;
        empty--;
        if(!curr_depth){
            curr_depth = q.size();
            depth++;
        }
    }

    if(empty){ //not all of them are ripen.
        cout << "-1";
    } else {
        cout << depth;
    }
    return 0;
}