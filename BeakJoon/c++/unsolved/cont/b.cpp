#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    if(a + b > n + 1){
        cout << "-1\n";
        return 0;
    } 
    for(int i = 1; i < a; i++)
        cout << i << ' ';
    cout << max(a, b) << ' ';
    for(int i = 0; i < n - a - b; i++)
        cout << 1 << ' ';
    if(a + b < n + 1)
        cout << max(a, b) << ' ';
    for(int i = b - 1; i > 0; i--)
        cout << i << ' ';

    return 0;
}