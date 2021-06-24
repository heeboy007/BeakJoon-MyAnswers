#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int N, M;
int answer[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
bool not_used[10] = {true, true, true, true, true, true, true, true, true, true};
vector<int> print_numbers;
ostringstream output;

void backtrack(int depth, int bound){
    if(depth == M){
        for(int i : answer){
            if(!i)
                break;
            output << print_numbers[i - 1] << ' ';
        }
        output << '\n';
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

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        print_numbers.push_back(input);
    }

    sort(print_numbers.begin(), print_numbers.end());
    backtrack(0, 1);
    cout << output.str();

    return 0;
}