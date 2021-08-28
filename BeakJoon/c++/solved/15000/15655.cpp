#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int answer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool not_used[10] = {true, true, true, true, true, true, true, true, true, true};
vector<int> print_numbers;

void backtrack(int depth, int bound){
    if(depth == M){
        for(int i : answer){
            if(!i)
                break;
            cout << print_numbers[i - 1] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = bound + 1; i <= N; i++){
        if(not_used[i]){
            answer[depth] = i;
            not_used[i] = false;
            backtrack(depth + 1, i);
            not_used[i] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        print_numbers.push_back(input);
    }

    sort(print_numbers.begin(), print_numbers.end());
    backtrack(0, 0);

    return 0;
}