#include<iostream>
#include<vector>
using namespace std;

//플로이드 와샬이 그런거임????
//난 다익밖에 몰랐는데 ㅠ

#define INF 1000000

int n, m;
int map[105][105];
int dist[105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    cin >> n >> m;
    while(m--){
      int a, b, cost;
      cin >> a >> b >> cost;
      map[a][b] = cost;
    }  
    
    for(int x = 1; x <= n; x++){
      for(int y = 1; y <= n; y++){
        if(x == y)
            dist[x][y] = 0;
        else if(map[x][y])
            dist[x][y] = map[x][y];
        else
            dist[x][y] = INF;
      }
    }

    for(int k = 1; k <= n; k++){
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
        }
      }
    }

    for(int x = 1; x <= n; x++){
      for(int y = 1; y <= n; y++){
        cout << dist[x][y] << ' ';
      }
      cout << '\n';
    }
  
    return 0;
}