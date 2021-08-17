#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, counter = 0;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int input;
        cin >> input;
        if(i != input)
            counter++;
    }

    cout << counter;

    return 0;
}