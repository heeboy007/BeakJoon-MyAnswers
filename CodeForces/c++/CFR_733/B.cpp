#include<iostream>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int h, w;
        int table[20][20];

        for(int i = 0; i < 20; i++)
            memset(table[i], 0, sizeof(table[i]));

        cin >> h >> w;
        for(int i = 0; i < h; i += 2){
            table[i][0] = 1;
        }
        for(int j = 2; j < w; j += 2){
            table[h - 1][j] = 1;
        }
        for(int i = h - 3; i >= 0; i -= 2){
            table[i][w - 1] = 1;
        }
        for(int j = w - 3; j >= 2; j -= 2){
            table[0][j] = 1;
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cout << table[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}