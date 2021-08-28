#include<iostream>
#include<vector>

using namespace std;

bool is_winner(int a, int b){
    if(a == 1 && b == 2)
        return true;
    if(a == 2 && b == 3)
        return true;
    if(a == 3 && b == 1)
        return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max = 1, curr = 1;
    bool is_last_winner_1;
    int rsp1[300] = {0,}, rsp2[300] = {0,};
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        rsp1[i] = input;
    }
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        rsp2[i] = input;
    }

    is_last_winner_1 = is_winner(rsp1[0], rsp2[0]);
    for(int i = 1; i < n; i++){
        if(rsp1[i] == rsp2[i]){
            is_last_winner_1 = !is_last_winner_1;
            curr = 1;
        } else {
            if(is_winner(rsp1[i], rsp2[i]) == is_last_winner_1){ // winner strike!
                curr++;
                max = (curr > max ? curr : max);
            } else { // winner change.
                is_last_winner_1 = !is_last_winner_1;
                curr = 1;
            }
        }
    }

    cout << max;

    return 0;
}