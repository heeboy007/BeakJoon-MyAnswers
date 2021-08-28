#include<iostream>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        long long friends;
        cin >> friends;

        if(friends < 6)
            cout << "15\n";
        else
            cout << ((friends + 1) / 2) * 5 << '\n';
    }

    return 0;
}