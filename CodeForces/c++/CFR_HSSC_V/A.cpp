#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while(n--){
        int input;
        cin >> input;

        cout << input / 10 + ((input % 10 == 9) ? 1 : 0) << '\n'; 
    }

    return 0;
}