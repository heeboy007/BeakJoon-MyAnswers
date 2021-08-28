#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long n, m, k;
    cin >> n >> m >> k;

    cout << (k / m) << ' ' << (k % m);

    return 0;
}