/*
 *  About naming rules
 *  1. All directory names must have CFR_ prefix.
 *  2. If contest has a number, the number is the main name.
 *  3. It contest doesn't have a number, make up a good acronym to be the main name.
 *  4. If vituraly anticipated the contest, add suffix _V.
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> login, logout;
    int n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        login.emplace_back(a);
        logout.emplace_back(a + b);
    }

    

    return 0;
}