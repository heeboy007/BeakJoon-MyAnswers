#include<iostream>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char map[5][10010];
    for(int i = 0; i < 5; i++){
        memset(map[i], 0, sizeof(char) * 10010);
        cin >> map[i];
    }

    int len = strlen(map[0]);
    for(int i = 0; i < len; i++){
        if(map[2][i] == 'm'){
            map[0][i] = 'o';
            map[1][i] = 'w';
            map[2][i] = 'l';
            map[3][i] = 'n';
            map[4][i] = '.';
        } else if(map[1][i] == 'w'){
            map[0][i] = '.';
            map[1][i] = 'o';
            map[2][i] = 'm';
            map[3][i] = 'l';
            map[4][i] = 'n';
        }
    }

    for(int i = 0; i < 5; i++){
        cout << map[i] << '\n';
    }

    return 0;
}