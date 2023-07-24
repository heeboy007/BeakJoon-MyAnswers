#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    std::cout << std::fixed;
    int a, b;
    cin >> a >> b;
    
    long double result = log10(a) * b;

    cout << (long long)((long double)floor(result) + 1);

    return 0;
}
