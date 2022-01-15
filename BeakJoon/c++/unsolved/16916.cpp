#include<iostream>

#define DIV 29
#define MOD 1000000007
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    ll pattern = 0, check = 0, n = b.size(), m = a.size(), base = 1;

    for(int i = 0; i < n; i++){
        pattern = pattern * DIV + (b[i] - 'a' + 1);
        check = check * DIV + (a[i] - 'a' + 1);
        if(i) base = base * DIV;
    }

    if(check == pattern){
        cout << "1";
        return 0;
    }

    for(int i = 0; i < m - n; i++){
        check = (check - (base * (a[i] - 'a' + 1))) * DIV + (a[i + n] - 'a' + 1);
        if(check == pattern){
            cout << "1";
            return 0;
        }
    }
    cout << "0";
    return 0;
}