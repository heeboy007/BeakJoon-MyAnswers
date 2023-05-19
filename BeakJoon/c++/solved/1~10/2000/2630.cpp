#include<iostream>

using namespace std;

int blue = 0, white = 0;
int map[150][150] = {0};

//device and conquer
int dq(int n, int x, int y) {
  if(n <= 1) {
    return map[x][y];
  }
  int result[5] = {
    dq(n / 2, x, y),
    dq(n / 2, x + n / 2, y),
    dq(n / 2, x, y + n / 2),
    dq(n / 2, x + n / 2, y + n / 2)
  };
  /*cout << "N : " << n << " X : " << x << " Y : " << y << '\n';
  cout << result[0] << '\n';
  cout << result[1] << '\n';
  cout << result[2] << '\n';
  cout << result[3] << '\n';*/
  if(result[0] == result[1] && result[1] == result[2] && result[2] == result[3]){
    //cout << "Same!\n";
    if(result[0] == 0)
      return 0;
    else if(result[0] == 1)
      return 1;
    else 
      return 2;
  } else {
      for(int i = 0; i < 4; i++){
        if(result[i] == 0)
          white++;
        else if(result[i] == 1)
          blue++;
      }
      return 2;
  }
  
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n = 0;
  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> map[i][j];
    }
  }
  
  
  int res = dq(n, 0, 0);
  if(res == 0)
    white++;
  else if(res == 1)
    blue++;
  
  cout << white << '\n' << blue;
  return 0;
}