#include<iostream>

using namespace std;

void app(){
    long long a, b, delta;
    cin >> a >> b;
    delta = a > b ? a - b : b - a;
    if(delta){
        long long moves = a % delta;
        moves = delta - moves < moves ? delta - moves : moves;
        cout << delta << ' ' << moves << '\n';
    } else {
        cout << "0 0\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        app();
    }

    return 0;
}