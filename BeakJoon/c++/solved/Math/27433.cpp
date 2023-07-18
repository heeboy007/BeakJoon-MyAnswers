#include <iostream>

using namespace std;

int main()
{
    long long n, ff = 1;
    
    cin >> n;
    
    for(long long i = 1; i <= n; i++){
        ff *= i;
    }
    cout << ff;

    return 0;
}
