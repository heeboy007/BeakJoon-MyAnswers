#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool is_simple = true, is_pel = true;
    int n;
    char first;
    string pel;
    cin >> pel;
    n = pel.length();
    first = pel[0];

    for(int i = 0; i < (n + 1) / 2; i++){
        if(pel[i] != pel[n - i - 1]){
            is_pel = false;
            break;
        }
        if(first != pel[i] || first != pel[n - i - 1])
            is_simple = false;
    }

    if(is_pel){
        if(is_simple)
            cout << "-1\n";
        else
            cout << n - 1 << '\n';
    } else {
        cout << n << '\n';
    }

    return 0;
}