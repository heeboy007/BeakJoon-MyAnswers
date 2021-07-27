#include<iostream>

using namespace std;

long gcd(long a, long b){
    if(!b)
        return a;
    else
        return gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;
    while(c--){
        long a, b;
        cin >> a >> b;
        if(a < b){
            long t = a;
            a = b;
            b = t;
        }
        cout << a * b / gcd(a, b) << '\n';
    }

    return 0;
}