#include<iostream>
#include<vector>

using namespace std;

pair<int, int> devide_conquer(pair<int, int> check_cord, int n, vector<vector<int>> &paper){
    int start_x = check_cord.first, start_y = check_cord.second;
    bool check = (paper[start_x][start_y] == 1), all_valid = true;
    pair<int, int> result = {0, 0};
    for(int i = start_x; i < start_x + n; i++){
        for(int j = start_y; j < start_y + n; j++){
            if(check ^ paper[i][j]){
                all_valid = false;
                break;
            }
        }
        if(!all_valid)
            break;
    }

    if(all_valid){
        if(check){ //1이 second
            result.second = 1;
        } else { //0이 first
            result.first = 1;
        }
    } else {
        pair<int, int> dv_result;
        vector<pair<int, int>> dv_try = {{start_x, start_y}, {start_x + n / 2, start_y},
            {start_x, start_y + n / 2}, {start_x + n / 2, start_y + n / 2}};
        for(pair<int, int> cord : dv_try){
            dv_result = devide_conquer(cord, n / 2, paper);
            result.first += dv_result.first;
            result.second += dv_result.second;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> paper;

    for(int i = 0; i < n; i++){
        vector<int> slice;
        for(int j = 0; j < n; j++){
            int input;
            cin >> input;
            slice.emplace_back(input);
        }
        paper.push_back(std::move(slice));
    }

    pair<int, int> result = devide_conquer({0, 0}, n, paper);
    cout << result.first << '\n' << result.second << '\n';

    return 0;
}