#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int myPow(int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    return x * myPow(x, p-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::string str;
    cin >> str;

    int index = 0, cutoff = str.size(), answer = 0;

    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(ch == '-'){
            cutoff = i;
            break;
        }
    }

    for(int i = str.size() - 1; i >= 0; i--){
        char ch = str[i];
        if(ch == '+' || ch == '-'){
            index = 0;
        } else {
            if(i < cutoff){ //+
                answer += myPow(10, index) * (ch - 48);
            } else { //-
                answer -= myPow(10, index) * (ch - 48);
            }
            index++;
        }
    }

    cout << answer;

    return 0;
}