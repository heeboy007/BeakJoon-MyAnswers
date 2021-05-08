#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int acc = 0;
    cin >> acc;

    if(acc == 4 || acc == 7){
        cout << "-1\n";
        return 0;
    }

    int index = acc / 5;
    for(int i = index; i >= 0; i--){
        if(!((acc - 5 * i) % 3)){
            cout << i + (acc - 5 * i) / 3;
            return 0;
        }
    }

    return 0;
}