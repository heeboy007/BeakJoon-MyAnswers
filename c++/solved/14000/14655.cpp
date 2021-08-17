#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, max = 0;
    cin >> n;

    if(n == 2){
        int a, b;
        cin >> a >> b;
        max += (a + b) > -1 * (a + b) ? (a + b) : -1 * (a + b);
        cin >> a >> b;
        max += (a + b) > -1 * (a + b) ? (a + b) : -1 * (a + b);
    } else {
        for(int i = 0; i < 2 * n; i++){
            int input;
            cin >> input;
            max += abs(input);
        }
    }

    cout << max;

    return 0;
}