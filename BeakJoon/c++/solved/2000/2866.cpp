#include<iostream>
#include<set>
#include<cstring>

#define DIV 71
#define MOD 1000000007

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, count = 0;
    cin >> a >> b;
    char grid[a][b];
    int cnt[a + 1][b];

    for(int i = 0; i < a; i++){
        cin >> grid[i];
    }
    memset(cnt[a], 0, sizeof(int) * b);

    for(int i = a - 1; i >= 0; i--){
        for(int j = 0; j < b; j++){
            if(i == a - 1)
                cnt[i][j] = grid[i][j] - 'a' + 1;
            else
                cnt[i][j] = cnt[i + 1][j] * DIV + grid[i][j] - 'a' + 1;
        }
    }

    for(int i = 0; i < a; i++){
        set<int> check(cnt[i + 1], cnt[i + 1] + b);
        if(check.size() != b)
            break;
        count++;
    }

    cout << count << endl;

    return 0;
}