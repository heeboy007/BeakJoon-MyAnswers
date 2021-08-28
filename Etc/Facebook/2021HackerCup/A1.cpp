#include<iostream>

using namespace std;

bool is_inside_of(char c){
    for(char t : "AEIOU"){
        if(t == c)
            return true;
    }
    return false;
}

void app(int case_num){
    int ans = -1;
    string change;
    string vowel = "AEIOU";
    cin >> change;

    //cout << change.size() << '\n';

    for(char c = 'A'; c <= 'Z'; c++){
        int cal = 0;
        bool is_changeable = true;

        for(char from : change){
            if(c == from){
                continue;
            } else if(is_inside_of(c) == is_inside_of(from)){
                cal += 2;
            } else {
                cal += 1;
            }
        }
        
        if(ans < 0)
            ans = cal;
        else
            ans = min(ans, cal);
    }

    cout << "Case #" << case_num << ": " << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int g;
    cin >> g;
    for(int i = 1; i <= g; i++){
        app(i);
    }

    return 0;
}