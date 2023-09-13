#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int what[100001];
    for(int i = 0; i < n; i++)
        cin >> what[i];

    sort(what, what + n);
    int curr = what[0];
    for(int i = 0; curr < what[n - 1];){
        cout << curr << ' ';
        i = lower_bound(what, what + n, curr + 1) - what;
        curr = what[i];
    }
    cout << curr;

    return 0;
}