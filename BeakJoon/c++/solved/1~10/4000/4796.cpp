#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int index = 1;
    while(true){
        int L, P, V;
        cin >> L >> P >> V;
        if(!(L | P | V))
            break;
        cout << "Case " << index << ": " << (V / P) * L + min(V % P, L) << '\n';
        index++;
    }

    return 0;
}