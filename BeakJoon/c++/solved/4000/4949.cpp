#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> vps;

    while(true){
        while(!vps.empty())
            vps.pop();

        string input;
        getline(cin, input);
        
        if(input == ".")
            break;

        bool valid = true;
        char c = '?';

        for(char c : input){
            if(c == '(' || c == '['){
                vps.push(c);
            }
            else if(c == ')'){
                if(vps.empty()){
                    valid = false;
                    break;
                } else if(vps.top() != '('){
                    valid = false;
                    break;
                } else {
                    vps.pop();
                }
            }
            else if(c == ']'){
                if(vps.empty()){
                    valid = false;
                    break;
                } else if(vps.top() != '['){
                    valid = false;
                    break;
                } else {
                    vps.pop();
                }
            }
        }

        if(vps.empty() && valid){
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}