#include<iostream>

using namespace std;

char stars[1 << 10 + 1][1 << 10 + 1];

void star(int n, int i, int j){
    if(n <= 1){
        stars[i][j] = '*';
        return;
    }
    star(n / 2, i, j);
    star(n / 2, i + n / 2, j);
    star(n / 2, i, j + n / 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    
    int input;
    cin >> input;
    star(1 << input, 0, 0);

    for(int i = 0, l = 0; i < (1 << input); i++, l++){
        for(int j = 0; j < (1 << input) - l; j++){
            if(stars[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}