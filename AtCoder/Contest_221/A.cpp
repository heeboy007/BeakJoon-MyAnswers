#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long base = 1;
    int a, b;
    cin >> a >> b;
    a -= b;
    while (a--)
        base *= 32;
    cout << base;

    return 0;
}