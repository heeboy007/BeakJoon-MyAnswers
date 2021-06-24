#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int answer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int same_index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//bool not_used[10] = {true, true, true, true, true, true, true, true, true, true};
vector<int> print_numbers;

void backtrack(int depth){
    if(depth == M){
        for(int i : answer){
            if(!i)
                break;
            cout << print_numbers[i - 1] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++){
        answer[depth] = i;
        backtrack(depth + 1);
        while(same_index[i - 1] == same_index[i])
            i++;
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

    int prev = 0, index = 0;
    for(int pr : print_numbers){
        same_index[index] = ((pr == prev) ? same_index[index - 1] : index);
        prev = pr;
        index++;
    }
    backtrack(0);

    return 0;
}