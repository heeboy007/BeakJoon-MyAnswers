#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){

    int a, b, g;
    cin >> a >> b;

    if(a > b)
        g = gcd(a, b);
    else
        g = gcd(b, a);
    
    cout << g << '\n';
    cout << a * b / g << '\n';

    return 0;
}