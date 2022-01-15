#include<iostream>
#include<cstring>
#include<sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    bool is_pen[26] = {0};
    cin >> t;
    cin.ignore();
    while(t--){
        string input;
        ostringstream os;
        getline(cin, input);
        for(char c : input){
            int i = c >= 'a' ? (c - 'a') : (c - 'A');
            if(0 <= i && i <= 26)
                is_pen[i] = true;
        }
        os << "missing ";
        for(char i = 'a'; i <= 'z'; i++){
            if(!is_pen[i - 'a'])
                os << i;
        }
        if(os.str().size() == 8)
            cout << "pangram\n";
        else
            cout << os.str() << '\n';
        memset(is_pen, 0, sizeof(bool) * 26);
    }

    return 0;
}