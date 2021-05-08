#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> numbers;
int answer[8];
bool is_used[8];
int n, m;

void back_track(int level){
    if(level == m){
        for(int i = 0; i < m; i++)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if(is_used[i]){
            continue;
        }
        is_used[i] = true;
        answer[level] = numbers.at(i - 1);
        back_track(level + 1);
        is_used[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    sort(numbers.begin(),numbers.end());

    back_track(0);
    return 0;
}