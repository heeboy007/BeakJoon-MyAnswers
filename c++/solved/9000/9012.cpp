#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count = 0;
    string str;
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> str;
        int stack = 0;
        for(char c : str){
            if(c == '(')
                stack++;
            else
                stack--;
            if(stack < 0)
                break;
        }
        if(stack){
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}