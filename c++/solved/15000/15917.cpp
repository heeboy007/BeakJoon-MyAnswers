#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while(q--){
        int input;
        cin >> input;
        if((input & (-input)) == input){
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}