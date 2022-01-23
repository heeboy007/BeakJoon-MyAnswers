#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        string a, b, c, d;
        cin >> a >> b;
        c = a, d = b;
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        if(c == d)
            cout << a << " & " << b << " are anagrams.\n";
        else
            cout << a << " & " << b << " are NOT anagrams.\n";
    }

    return 0;
}