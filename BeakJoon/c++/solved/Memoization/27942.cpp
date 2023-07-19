#include <iostream>

using namespace std;

int map[3005][3005] = {0};
int sum[3005][3005] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    int x1 = n / 2, y1 = n / 2;
    int x2 = n / 2 + 1, y2 = n / 2 + 1;
    
    for(int i = 1; i <= n + 1; i++) {
        for(int j = 1; j <= n + 1; j++) {
            if((i != n + 1) && (j != n + 1))
                cin >> map[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
            //cout << sum[i][j] << ' ';
        }
        //cout << '\n';
    }

    string s = "";
    int acc = 0;
    while(true){
        int val[5] = {0, 0, 0, 0};
        //int testval[5] = {0, 0, 0, 0};
        
        if(x1 - 1)
            val[0] = sum[x1 - 1][y2] - sum[x1 - 1][y1 - 1] - sum[x1 - 2][y2] + sum[x1 - 2][y1 - 1];
        if(x2 + 1 <= n)
            val[1] = sum[x2 + 1][y2] - sum[x2 + 1][y1 - 1] - sum[x2][y2] + sum[x2][y1 - 1];
        if(y1 - 1)
            val[2] = sum[x2][y1 - 1] - sum[x1 - 1][y1 - 1] - sum[x2][y1 - 2] + sum[x1 - 1][y1 - 2];
        if(y2 + 1 <= n)
            val[3] = sum[x2][y2 + 1] - sum[x1 - 1][y2 + 1] - sum[x2][y2] + sum[x1 - 1][y2];
        
        /*for(int i = y1; i <= y2; ){
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
        }*/
        
        /*
        if(val[0] != testval[0])
            cout << "incorrect 0 " << val[0] << " : " << testval[0] << '\n';
        if(val[1] != testval[1])
            cout << "incorrect 3 (" << x1 << ',' << y1 << ")/("<< x2 << ',' << y2 << ") " << val[1] << " : " << testval[1] << '\n';
        if(val[2] != testval[2])
            cout << "incorrect 2 " << val[2] << " : " << testval[2] << '\n';
        if(val[3] != testval[3])
            cout << "incorrect 3 (" << x1 << ',' << y1 << ")/("<< x2 << ',' << y2 << ") " << val[3] << " : " << testval[3] << '\n';
        */
        
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
