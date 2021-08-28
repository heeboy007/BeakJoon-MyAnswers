#include<iostream>
#include<cstring>

#define BIG_PRIME 1234567891

using namespace std;

long long mod31(long long x){
    if(x)
        return (mod31(x - 1) * 31) % BIG_PRIME;
    else
        return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char buffer[60];
    int L;
    long long sum = 0;

    memset(buffer, 0, sizeof(buffer));

    cin >> L;
    cin >> buffer;

    for(int i = 0; i < L; i++){
        sum += (long long)(buffer[i] - 96) * mod31(i);
    }
    sum %= BIG_PRIME;

    cout << sum;

    return 0;
}