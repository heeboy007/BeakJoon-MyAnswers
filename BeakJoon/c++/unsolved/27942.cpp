/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int map[3002][3002] = {0};

int main()
{
    int n;
    cin >> n;
    
    int x1 = n / 2, y1 = n / 2;
    int x2 = n / 2 + 1, y2 = n / 2 + 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    string s = "";
    int acc = 0;
    while(true){
        int val[5] = {0, 0, 0, 0};
        
        for(int i = y1; i <= y2; ){
            val[0] += map[x1 - 1][i++];
        }
        for(int i = y1; i <= y2; ){
            val[1] += map[x2 + 1][i++];
        }
        for(int i = x1; i <= x2; ){
            val[2] += map[i++][y1 - 1];
        }
        for(int i = x1; i <= x2; ){
            val[3] += map[i++][y2 + 1];
        }
        
        int count = 0;
        char type = ' ';
        for(int i = 0; i < 4; i++){
            if(count < val[i]){
                count = val[i];
                switch(i) {
                    case 0:
                        type = 'U';
                        break;
                    case 1:
                        type = 'D';
                        break;
                    case 2:
                        type = 'L';
                        break;
                    case 3:
                        type = 'R';
                        break;
                }
            }
        }
        //cout << type << '\n';
        switch(type) {
            case 'U':
                x1 -= 1;
                break;
            case 'D':
                x2 += 1;
                break;
            case 'L':
                y1 -= 1;
                break;
            case 'R':
                y2 += 1;
                break;
        }
        if(count <= 0){
            break;
        } else {
            s += type;
            acc += count;
        }
    }
    
    cout << acc << '\n' << s;
    
    return 0;
}
