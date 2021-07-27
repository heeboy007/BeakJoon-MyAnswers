#include<iostream>
#include<cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k, sum_5 = 0, sum_2 = 0, base = 5;
    cin >> n >> m;
    k = n - m;

    while(n >= base){
        sum_5 += (n / base) - (m / base) - (k / base);
        base *= 5;
    }
    base = 2;
    while(n >= base){
        sum_2 += (n / base) - (m / base) - (k / base);
        base *= 2;
    }

    cout << min(sum_5, sum_2);
    return 0;
}