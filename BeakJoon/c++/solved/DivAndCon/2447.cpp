#include <iostream>

using namespace std;

char map[2200][2200] = {0};

void recur(int n, int x, int y){
    if(n != 3){
        n /= 3;
        for(int a = 0; a < 3 * n; a += n){
            for(int b = 0; b < 3 * n; b += n){
                //cout << a << ':' << b << '\n';
                if(a == n && b == n) {
                    for(int c = x + a; c < x + a + n; c++){
                        for(int d = y + b; d < y + b + n; d++){
                            map[c][d] = ' ';
                        }
                    }
                } else {
                    recur(n, x + a, y + b);
                }
            }
        }
    } else {
        for(int a = 0; a < 3; a++){
            for(int b = 0; b < 3; b++){
                if(a == 1 && b == 1) {
                    map[x + a][y + b] = ' ';
                } else {
                    map[x + a][y + b] = '*';
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    recur(n, 0, 0);
    
    for(int i = 0; i < n; i++){
        cout << map[i] << '\n';
    }

    return 0;
}
