#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int part, kills = 5;
    string em;
    cin >> part >> em;
    part = 1;
    
    for(char c : em){
        if(c == 'W'){
            part++;
        } else { // c == 'P'
            if(part == 1){
                kills = (kills == 5 ? 1 : 5);
            } else if(part == 2) {
                kills = 6;
            } //does nothing if part >= 3
        }
    }

    if(part >= 3){
        cout << kills;
    } else {
        cout << "0";
    }

    return 0;
}