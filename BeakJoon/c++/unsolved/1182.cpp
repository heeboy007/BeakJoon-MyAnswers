#include<iostream>

using namespace std;

int n, m, target, count = 0;
int comb[25], numbers[25];
bool is_used[25];

void backtrack(int i, int start){
    if(i == m){
        int sum = 0;
        for(int j = 0; j < m; j++)
            sum += comb[j];
        if(sum == target)
            count++;
        return;
    }
    for(int j = start; j < n; j++){
        if(is_used[j])
            continue;
        is_used[j] = true;
        comb[i] = numbers[j];
        backtrack(i + 1, j);
        is_used[j] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> target;
    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    for(int k = 1; k <= n; k++){
        m = k;
        backtrack(0, 0);
    }
    cout << count;

    return 0;
}