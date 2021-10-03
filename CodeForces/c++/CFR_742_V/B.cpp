/*
 *  About naming rules
 *  1. All directory names must have CFR_ prefix.
 *  2. If contest has a number, the number is the main name.
 *  3. It contest doesn't have a number, make up a good acronym to be the main name.
 *  4. If vituraly anticipated the contest, add suffix _V.
 */

#include<iostream>
#include<cstring>

using namespace std;

int xorTillN(int a){
    switch (a % 4)
    {
    case 0:
        return a;
    case 1:
        return 1; 
    case 2:
        return a + 1; 
    case 3:
        return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;

        if(b == xorTillN(a - 1)){
            cout << a << '\n';
        } else if(b == xorTillN(a)) {
            cout << a + 2 << '\n';
        } else {
            cout << a + 1 << '\n';
        }
    }

    return 0;
}