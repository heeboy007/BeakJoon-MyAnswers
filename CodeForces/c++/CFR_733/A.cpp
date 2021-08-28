#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        string input;
        cin >> input;
        int max = 1;
        for(char c : input){
            if(c - '0' > max)
                max = c - '0';
        }
        cout << max << '\n';
    }

    return 0;
}