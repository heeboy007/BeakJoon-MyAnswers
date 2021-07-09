#include<iostream>
#include<queue>

#define MAX 101

using namespace std;

typedef struct _CORD{
    int x;
    int y;
    int z;
} Cord;

int tray[MAX][MAX][MAX];

void add_cord_to_queue(queue<Cord> *q, int x, int y, int z){
    tray[x][y][z] = 1;
    Cord cord;
    cord.x = x;
    cord.y = y;
    cord.z = z;
    q->push(cord);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<Cord> q;
    int empty = 0, depth = -1; //which is the time.
    int n, m, h;
    cin >> n >> m >> h;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                cin >> tray[k][j][i];
                if(tray[k][j][i] > 0){
                    Cord cord;
                    cord.x = k;
                    cord.y = j;
                    cord.z = i;
                    q.push(cord);
                    empty++;
                }
                else if(!tray[k][j][i]){
                    empty++;
                }
            }
        }
    }

    int curr_depth = q.size();
    while(!q.empty()){
        int x = q.front().x, y = q.front().y, z = q.front().z;
        q.pop();
        if(x + 1 < n){ //valid
            if(tray[x + 1][y][z] == 0){ //is 0
                add_cord_to_queue(&q, x + 1, y, z);
            }
        }
        if(x - 1 >= 0){
            if(tray[x - 1][y][z] == 0){ //is 0
                add_cord_to_queue(&q, x - 1, y, z);
            }
        }
        if(y + 1 < m){ //valid
            if(tray[x][y + 1][z] == 0){ //is 0
                add_cord_to_queue(&q, x, y + 1, z);
            }
        }
        if(y - 1 >= 0){
            if(tray[x][y - 1][z] == 0){ //is 0
                add_cord_to_queue(&q, x, y - 1, z);
            }
        }
        if(z + 1 < h){ //valid
            if(tray[x][y][z + 1] == 0){ //is 0
                add_cord_to_queue(&q, x, y, z + 1);
            }
        }
        if(z - 1 >= 0){
            if(tray[x][y][z - 1] == 0){ //is 0
                add_cord_to_queue(&q, x, y, z - 1);
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