#include<iostream>

using namespace std;

int N, M;
int answer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//bool is_used[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void backtrack(int depth, int bound){
    if(depth == M){
        for(int i : answer){
            if(!i)
                break;
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = bound; i <= N; i++){
        answer[depth] = i;
        backtrack(depth + 1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    backtrack(0, 1);

    return 0;
}