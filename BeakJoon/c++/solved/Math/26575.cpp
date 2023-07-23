#include <iostream>

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;
    int n;
    cin >> n;
    
    while(n--){
        double a, b, c;
        cin >> a >> b >> c;
        
        cout << '$' << a * b * c << '\n';
    }
    
    return 0;
}
