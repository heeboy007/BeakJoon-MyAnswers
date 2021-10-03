#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    string temp;
    cin >> N;

    temp = N;
    for(int i = 0; i < N.size() / 2; i++){
        temp[i] = (char)min(N[i], N[N.size() - i - 1]);
        temp[N.size() - i - 1] = (char)min(N[i], N[N.size() - i - 1]);
        if(N[i] > N[N.size() - i - 1]){
            if(i == 0){ // leading zero! 예외적인 상황
                temp = "";
                for(int j = 0; j < N.size() - 1; j++)
                    temp += '9';
                break;
            } else {
                for(int j = i + 1; j < (N.size() + 1) / 2; j++){
                    temp[j] = '9';
                    temp[N.size() - j - 1] = '9';
                }
                break;
            }
        }
    }
    cout << temp;

    for(int i = 0; i < N.size(); i++){
        N[i] -= temp[i];
    }

    string new_N = "0";
    for(int i = N.size() - 1; i >= 0 && N[i]; i++){
        new_N += N[i];
    }
    cout << new_N;

    return 0;
}