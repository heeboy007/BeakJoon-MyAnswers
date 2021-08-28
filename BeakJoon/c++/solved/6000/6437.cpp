#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 1;
    do{
        int p, s;
        cin >> p >> s;

        if(!p){
            return 0;
        }

        cout << "Hole #" << i++ << '\n';
        if(s == 1){
            cout << "Hole-in-one.\n";
        } else {
            if(p - s <= -2){
                cout << "Double Bogey.\n";
            } else if (p - s <= -1){
                cout << "Bogey.\n";
            } else if (p - s <= 0){
                cout << "Par.\n";
            } else if (p - s <= 1){
                cout << "Birdie.\n";
            } else if (p - s <= 2){
                cout << "Eagle.\n";
            } else{
                cout << "Double eagle.\n";
            }
        }
        cout << "\n";
    } while(true);

    return 0;
}