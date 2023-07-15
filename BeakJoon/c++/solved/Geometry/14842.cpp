#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    cout.precision(10);
    
    int w, h, n;
    cin >> h >> w >> n;
    
    int t = n / 2 + n % 2;
    double sum = 0.0;
    for(int i = 1; i < t; i++){
        sum += w * (1.0 - (2.0 * i / n));
    }
    sum *= 2.0;
    cout << sum;
 
    return 0;
}
