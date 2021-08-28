#include<iostream>
#include<cstring>

using namespace std;

int dp[1000001];

int min(int a, int b, int c){
    if(a < b){
        return c < a ? c : a;
    } else {
        return c < b ? c : b;
    }
}

int make_one(int n){
    if(dp[n] >= 0){
        return dp[n];
    } else {
        int min3, min2;
        int min = 0;
        min3 = !(n % 3) ? make_one(n / 3) : -1;
        min2 = !(n % 2) ? make_one(n / 2) : -1;
        min = make_one(n - 1);
        if(min3 >= 0 && min3 < min)
            min = min3;
        if(min2 >= 0 && min2 < min)
            min = min2;
        return dp[n] = min + 1;
    }
}

int main(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    cout << make_one(n);

    return 0;
}