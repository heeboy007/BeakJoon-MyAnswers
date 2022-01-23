#include<iostream>

using namespace std;

int triangle[505][505];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, maximum = 0;
    cin >> n;
    for(int i = 0; i <= n; i++){
        triangle[i][0] = 0;
        triangle[0][i] = 0; 
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cin >> triangle[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            triangle[i][j] = max(triangle[i - 1][j] + triangle[i][j], triangle[i - 1][j - 1] + triangle[i][j]);
            if(i == n)
                maximum = max(maximum, triangle[i][j]);
        }
    }
    cout << maximum;

    return 0;
}