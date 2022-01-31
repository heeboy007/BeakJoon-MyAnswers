#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int atm[n] = {0}, sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> atm[i];
    sort(atm, atm + n);
    
    for(int i =0; i < n; ++i)
        sum += atm[i] * (n - i);
    cout << sum;

    return 0;
}