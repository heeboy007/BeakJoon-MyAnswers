#include<iostream>
#include<vector>

using namespace std;

long long comb(int n, int r){
    long long p = 1, c = 1;
    while(r > 0){ 
        c*=n--;
        p*=r--; 
    } 
    return c / p;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(16);

    int n, m, k;
    long long sum = 0;
    cin >> n >> m >> k;
    
    for(int i = k; i <= m; i++){
        if(n - m < m - i)
            continue;
        sum += comb(m, i) * comb(n - m, m - i);
    }

    cout << (double)sum / comb(n, m);

    return 0;
}