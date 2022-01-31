#include<iostream>

using namespace std;

int n, m;
int numbers[10];
bool is_used[10];

void backtrack(int i, int start){
    if(i == m){
        for(int j = 0; j < m; j++)
            cout << numbers[j] << ' ';
        cout << '\n';
        return;
    }
    for(int j = start; j <= n; j++){
        if(is_used[j])
            continue;
        is_used[j] = true;
        numbers[i] = j;
        backtrack(i + 1, j);
        is_used[j] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    backtrack(0, 1);

    return 0;
}