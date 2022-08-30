#include<iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    if(a > b){
        if(c > a)
            cout << b << ' ' << a << ' ' << c;
        else{
            if(b > c)
                cout << c << ' ' << b << ' ' << a;
            else
                cout << b << ' ' << c << ' ' << a;
        }
    } else { // b > a
        if(c > b)
            cout << a << ' ' << b << ' ' << c;
        else{
            if(a > c)
                cout << c << ' ' << a << ' ' << b;
            else
                cout << a << ' ' << c << ' ' << b;
        }
    }
    
    return 0;
}