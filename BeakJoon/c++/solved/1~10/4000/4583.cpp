#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        bool is_invalid = false;
        string input;
        cin >> input;
        if(input == "#")
            break;
        string output = "";
        for(int i = input.size() - 1; i >= 0; i--){
            
            switch(input[i]){
                case 'b':
                    output += 'd';
                    break;
                case 'd':
                    output += 'b';
                    break;
                case 'p':
                    output += 'q';
                    break;
                case 'q':
                    output += 'p';
                    break;
                case 'i' : case 'o' : case 'v' : case 'w' : case 'x' :
                    output += input[i];
                    break;
                default:
                    cout << "INVALID\n";
                    is_invalid = true;
                    break;
            }
            if(is_invalid)
                break;
        }
        if(!is_invalid)
            cout << output << '\n';
    }

    return 0;
}