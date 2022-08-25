#include <iostream>
using namespace std;

long long map[205][205];
long long dist[205][205];

#define INF 10000000000L

int main() {
    
    int n, m, x, q;
    long long vaild = 0, vaild_sum = 0;
    cin >> n >> m >> x >> q;
    while(m--){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        map[a][b] = c;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)
                dist[i][j] = 0;
            else if(map[i][j]){
                if(i <= x || j <= x)
                    dist[i][j] = map[i][j];
                else
                    dist[i][j] = INF;
            }
            else
                dist[i][j] = INF;
        }
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i <= x || j <= x)
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                else{
                    if(k <= x)
                        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    
    while(q--){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] != INF){
            vaild++;
            vaild_sum += dist[a][b];
        }
    }
    
    cout << vaild << '\n' << vaild_sum;

	return 0;
}
