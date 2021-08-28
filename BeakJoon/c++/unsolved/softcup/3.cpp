#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int n;
int buildings[2001];
double slope[2001][2001];

int dfs(int start, double last_slope){
    int maximum = 0;
    for(int i = start + 1; i < n; i++){
        if(n - i <= maximum) //이미 최대 개수보다 적은 수의 빌딩만이 남았음.
            break;
        if(slope[start][i] >= last_slope)
            maximum = max(maximum, dfs(i, slope[start][i]));
    }
    return maximum + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    memset(buildings, 0, sizeof(int) * 2001);
    for(int i = 0; i < n; i++){
        cin >> buildings[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            slope[i][j] = (double)(buildings[j] - buildings[i]) / (double)(j - i);
        }
    }

    int maximum = 0;
    for(int i = 0; i < n; i++){
        if(n - i <= maximum) //이미 최대 개수보다 적은 수의 빌딩만이 남았음.
            break;
        maximum = max(maximum, dfs(i, -10000000000.0f));
    }

    cout << n - maximum;

    return 0;
}