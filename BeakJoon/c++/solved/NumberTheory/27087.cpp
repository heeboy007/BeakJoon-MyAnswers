#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){
        int a, b, c, p, count = 0;
        cin >> a >> b >> c >> p;
        count += (!(a % p) ? 1 : 0);
        count += (!(b % p) ? 1 : 0);
        count += (!(c % p) ? 1 : 0);
        if(count >= 2){
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
