#include<iostream>
#include<sstream>
//#include<cstring>

#define LL long long
#define MAX 1000005

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    
    int t;
    ostringstream out;
    LL arr[MAX] = {0};
    LL sum[MAX] = {0};
    cin >> t;
    
    for(int i = 2; i < MAX; i++){
        for(int j = 1; i * j < MAX; j++){
            arr[i * j] += i;
        }
    }
    
    for(int i = 1; i < MAX; i++){
        sum[i] = arr[i] + sum[i - 1];
    }
    
    while(t--){
        LL n;
        cin >> n;
        out << sum[n] + n << '\n';
    }
    cout << out.str();

    return 0;
}