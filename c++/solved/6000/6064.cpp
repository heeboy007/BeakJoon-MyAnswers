#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, m, x, y, result = -1;
        cin >> n >> m >> x >> y;
        x--; y--;
        for(int i = 0; i < m; i++){
            if((i * n + x) % m == y){
                result = (i * n + x) + 1;
                break;
            }
        }
        cout << result << '\n';
    }

    return 0;
}