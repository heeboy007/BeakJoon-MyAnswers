#include<iostream>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, target;
    int map[31][31], row[31], col[31];
    cin >> n >> target;

    memset(row, 0, sizeof(int) * 31);
    memset(col, 0, sizeof(int) * 31);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }

    bool update = true;
    while(update){

        //최적화 할 수 있는 부분이었지만... 31개로 그다지 데이터가 크지 않아서 놔둠.
        memset(row, 0, sizeof(int) * 31);
        memset(col, 0, sizeof(int) * 31);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                row[i] += map[i][j];
                col[i] += map[j][i];
            }
        }

        update = false;
        for(int i = 0; i < n; i++){
            if(target){
                if(row[i] != n && row[i] > (n - 1) / 2){
                    for(int j = 0; j < n; j++)
                        map[i][j] = target;
                    update = true;
                }
                if(col[i] != n && col[i] > (n - 1) / 2){
                    for(int j = 0; j < n; j++)
                        map[j][i] = target;
                    update = true;
                }
            } else {
                if(row[i] != 0 && row[i] <= (n - 1) / 2){
                    for(int j = 0; j < n; j++)
                        map[i][j] = target;
                    update = true;
                }
                if(col[i] != 0 && col[i] <= (n - 1) / 2){
                    for(int j = 0; j < n; j++)
                        map[j][i] = target;
                    update = true;
                }
            }
        }
    }
    
    bool complete = true;
    for(int i = 0; i < n; i++){
        if(row[i] != target * n)
            complete = false;
        if(col[i] != target * n)
            complete = false;
    }

    cout << (complete ? '1' : '0');

    return 0;
}