/*
 *  About naming rules
 *  1. All directory names must have CFR_ prefix.
 *  2. If contest has a number, the number is the main name.
 *  3. It contest doesn't have a number, make up a good acronym to be the main name.
 *  4. If vituraly anticipated the contest, add suffix _V.
 */

#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int last_index, check = 0;
    string S, T;
    cin >> S >> T;

    for(int i = 0; i < S.length(); i++){
        if(S[i] != T[i]){
            check++;
            last_index = i;
        }
    }

    if(check == 0){
        cout << "Yes";
    } else if(check == 2 && S[last_index - 1] != T[last_index - 1]){
        if(S[last_index - 1] == T[last_index] && S[last_index] == T[last_index - 1])
            cout << "Yes";
        else
            cout << "No";
    } else {
        cout << "No";
    }

    return 0;
}