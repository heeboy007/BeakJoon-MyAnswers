#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int a[100], b[100];
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a, a+n);
    sort(b, b+n);

    int sum = 0;

    for(int i = 0; i < n; i++){
        //cout << a[i] << " : " << b[i] << '\n';
        sum += a[i] * b[n - i - 1];
    }
    cout << sum;

    return 0;
}