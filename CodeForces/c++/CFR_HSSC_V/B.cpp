#include<iostream>

using namespace std;

int tar_length, base_length;
string base, target;

bool is_answer(int chip, int curr, bool is_moving_right){
    if(curr + 1 >= tar_length)
        return true;
    char next = target[curr + 1];
    bool result = false;
    if(chip > 0){
        if(base[chip - 1] == next)
            result = is_answer(chip - 1, curr + 1, false);
    }
    if(chip < (base_length - 1) && !result && is_moving_right){
        if(base[chip + 1] == next)
            result = is_answer(chip + 1, curr + 1, true);
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        base.clear();
        target.clear();
        cin >> base >> target;
        tar_length = target.length();
        base_length = base.length();
        char start = target[0];
        bool yes = false;
        for(int i = 0; i < base_length; i++){
            if(base[i] == start){
                if(is_answer(i, 0, true)){
                    yes = true;
                    break;
                }
            }
        }
        cout << (yes ? "YES\n" : "NO\n");
    }

    return 0;
}